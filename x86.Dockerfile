# https://hub.docker.com/_/gcc
# FROM gcc:9
FROM rikorose/gcc-cmake:latest

COPY . /usr/src/myapp
WORKDIR /usr/src/myapp

RUN chmod +x run.sh
CMD ["sh", "-c", "./run.sh"]