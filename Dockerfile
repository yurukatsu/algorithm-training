FROM python:3.12-slim-bookworm

ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Asia/Tokyo

WORKDIR /app

ARG GCC_VERSION=12
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc-${GCC_VERSION} \
    g++-${GCC_VERSION} \
    git \
    time \
    tree \
    tzdata

ARG ACL_TAG=v1.5.1
ARG ACL_PATH="/lib/ac-library"
RUN git clone https://github.com/atcoder/ac-library.git -b ${ACL_TAG} ${ACL_PATH}

RUN pip3 install atcoder-tools markupsafe==2.0.1

CMD ["bash"]
