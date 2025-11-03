#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    userp->append((char*)contents, size * nmemb);
    return size * nmemb;
}

class GroqClient {
private:
    std::string api_key;
    std::string base_url;
    
public:
    GroqClient(const std::string& key) 
        : api_key(key), base_url("https://api.groq.com/openai/v1/completions") {}
    
    std::string completion(const std::string& model, 
                          const std::string& prompt) {
        CURL* curl;
        CURLcode res;
        std::string response_string;
        
        curl = curl_easy_init();
        if(!curl) {
            throw std::runtime_error("Failed to initialize CURL");
        }
        
        json payload = {
            {"model", model},
            {"messages", json::array({
                {{"role", "user"}, {"content", prompt}}
            })}
        };
        
        std::string json_str = payload.dump();
        
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        std::string auth_header = "Authorization: Bearer " + api_key;
        headers = curl_slist_append(headers, auth_header.c_str());
        
        curl_easy_setopt(curl, CURLOPT_URL, base_url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_str.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
        
        res = curl_easy_perform(curl);
        
        if(res != CURLE_OK) {
            curl_easy_cleanup(curl);
            curl_slist_free_all(headers);
            throw std::runtime_error("CURL request failed: " + 
                                   std::string(curl_easy_strerror(res)));
        }
        
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
        
        return response_string;
    }
    
    std::string extract_text(const std::string& response) {
        try {
            json j = json::parse(response);
            return j["choices"][0]["text"];
        } catch (const std::exception& e) {
            return "Error parsing response: " + std::string(e.what());
        }
    }
};