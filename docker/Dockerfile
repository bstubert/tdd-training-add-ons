FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

# Fix for bug: Missing privilege separation directory
# (see https://bugs.launchpad.net/ubuntu/+source/openssh/+bug/45234)
RUN mkdir -p /run/sshd

RUN apt-get update && apt-get -y dist-upgrade

RUN apt-get -y install --fix-missing \
        build-essential \
        bzip2 \
        ccache \
        cmake \
        curl \
        git \
        lsb-release \
        ninja-build \
        python3 \
        python3-pip \
        ssh \
        sudo \
        tar \
        unzip \
        vim \
        wget


# Build googletest and googlemock 1.11.0 and install them in /usr/local
#WORKDIR /var/tmp
#RUN git clone https://github.com/google/googletest.git -b release-1.11.0 && \
#    cd googletest && \
#    mkdir build && \
#    cd build && \
#    cmake .. && \
#    make -j4 && \
#    make install

# Build Qt 5.15 and install it in /usr/local
#RUN apt-get -y install --fix-missing \
#    bison \
#    flex \
#    gperf \
#    libasound2-dev \
#    libcap-dev \
#    libdbus-1-dev \
#    libegl1-mesa-dev \
#    libevent-dev \
#    libfontconfig1-dev \
#    libglu1-mesa-dev \
#    libgstreamer-plugins-bad1.0-dev \
#    libgstreamer-plugins-base1.0-dev \
#    libgstreamer-plugins-good1.0-dev \
#    libgstreamer1.0-dev \
#    libnss3-dev \
#    libpci-dev \
#    libpulse-dev \
#    libudev-dev \
#    libx11-xcb-dev \
#    '^libxcb.*-dev' \
#    libxcomposite-dev \
#    libxcursor-dev \
#    libxdamage-dev \
#    libxi-dev \
#    libxkbcommon-dev \
#    libxkbcommon-x11-dev \
#    libxrandr-dev \
#    libxrender-dev \
#    libxss-dev \
#    libxtst-dev \
#    nodejs
#RUN wget -q https://download.qt.io/archive/qt/5.15/5.15.2/single/qt-everywhere-src-5.15.2.tar.xz && \
#    tar xf qt-everywhere-src-5.15.2.tar.xz && \
#    mkdir build && \
#    cd build && \
#    ../qt-everywhere-src-5.15.2/configure -prefix /usr/local -opensource -confirm-license \
#        -make libs -make tools && \
#    make -j32 && \
#    make install

# Clean up packages and builds
WORKDIR /
RUN apt-get autoremove -y && apt-get clean && \
    rm -rf /var/tmp/* && \
    ldconfig

# Set up user "tdd"

RUN groupadd -g 1000 tdd && \
  useradd -m -u 1000 -g 1000 -d /home/tdd -s /bin/bash tdd && \
  usermod -a -G adm,cdrom,sudo,dip,plugdev tdd && \
  echo 'tdd:tdd' | chpasswd && \
  echo "tdd   ALL=(ALL:ALL) ALL" >> /etc/sudoers

USER tdd
WORKDIR /home/tdd

RUN sed -i 's/\\h/docker/;s/01;32m/01;33m/' /home/tdd/.bashrc \
  && mkdir -p /home/tdd/project
