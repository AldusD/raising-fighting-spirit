# game

## How to run
```bash
    docker build -t mygame .
    docker run  -it --rm mygame
```

    After ending development, run this to clean memory usage
```bash
    docker rmi -f $(docker images -a -q)
```

docker-compose up --build

docker-compose run --rm app
