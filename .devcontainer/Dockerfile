FROM debian:latest

RUN apt update && apt-get install --no-install-recommends -y \
    build-essential \
    curl \
    freeglut3-dev \
    git \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
