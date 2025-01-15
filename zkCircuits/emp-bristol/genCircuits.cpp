#include <cstdint>
#include "emp-tool/emp-tool.h"
using namespace emp;

void matmul(int dim) {
	Integer a(8, 0, ALICE);
	Integer b(8, 0, ALICE);
	Integer *A = new Integer[dim*dim];
	Integer *B = new Integer[dim*dim];
	Integer *C = new Integer[dim*dim];
	for(int i = 0; i < dim; ++i)
		for(int j = 0; j < dim; ++j) {
			A[i*dim+j] = a;
			B[i*dim+j] = b;
		}
	for(int i = 0; i < dim; ++i)
		for(int j = 0; j < dim; ++j) {
			C[i*dim+j] = Integer(8, 0, PUBLIC);
			for(int k = 0; k < dim; ++k)
				C[i*dim+j] = C[i*dim+j] + A[i*dim+k]*B[k*dim+j];
		}
	for(int i = 0; i < dim; ++i)
		for(int j = 0; j < dim; ++j)
			C[i*dim+j].reveal<string>();
}

void comp(int n) {
	Integer a(n, 1, ALICE);
	Integer b(n, 0, BOB);
	Bit c = a.geq(b);
	c.reveal<bool>();
}

int main(int argc, char** argv) {
	setup_plain_prot(true, "matmul8.txt");
	// matmul(4);
	matmul(4);
	finalize_plain_prot();
	BristolFormat bf("matmul8.txt");
	bf.to_file("matmul8_file.h", "matmul8");
}