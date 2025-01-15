docker build -t circ .
id=$(docker create circ)
docker cp $id:/emp-tool/matmul8.txt circuits/
docker cp $id:/emp-tool/matmul8_file.h circuits/
docker rm -v $id