FROM debian:latest

RUN apt update && apt-get install --no-install-recommends -y \
    build-essential \
    curl \
    freeglut3-dev \
    git \
    locales &&\
    sed -i -E 's/# (ja_JP.UTF-8)/\1/' /etc/locale.gen && \
    locale-gen && \
    rm -rf /var/lib/apt/lists/*

ENV LANG=ja_JP.UTF-8
ENV LC_ALL=ja_JP.UTF-8

WORKDIR /app
