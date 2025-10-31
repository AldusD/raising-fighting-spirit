FROM gcc:13

WORKDIR /app

COPY . .

# compile with g++ 
# the file ending with .cpp under src 
# using c++ version 20 
# into a exec file named game
RUN g++ $(find src -name "*.cpp") -std=c++20 -o game

# Default command to run your game
CMD ["./game"]
