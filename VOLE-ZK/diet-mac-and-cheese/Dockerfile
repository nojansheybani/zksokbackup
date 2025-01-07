FROM rustlang/rust:nightly

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install \
    -y --no-install-recommends --no-install-suggests vim git

RUN git clone https://github.com/nojansheybani/swanky.git
RUN cd swanky/diet-mac-and-cheese && cargo build --release
# WORKDIR Mozzarella/target/release