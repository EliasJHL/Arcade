FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential \
    curl \
    wget \
    emacs \
    python3 \
    python3-pip \
    x11-xserver-utils \
    libx11-6 \
    libxext6 \
    libxrender1 \
    libxtst6 \
    libxi6 \
    libxrandr2 \
    libgl1-mesa-glx \
    xauth \
    cmake \
    git \
    libfreetype6-dev \
    libx11-dev \
    libxcursor-dev \
    libxrandr-dev \
    libudev-dev \
    libgl1-mesa-dev \
    libopenal-dev \
    libflac-dev \
    libvorbis-dev \
    libxcb1-dev \
    libudev-dev \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . /app/

ENTRYPOINT ["tail", "-f", "/dev/null"]