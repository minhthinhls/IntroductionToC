int main() {
	int t0 = 0x01101000;
	int t2;
	if (t0 < 0) {
		t2 = 1;
	} else {
		t2 = 0;
	}
	
	if (t2 != 0) {
		t2 = t2 + 2;
	} else {
		t0 = 0 - t0;
	}
	printf("t0 = %x\n", t0);
	printf("t2 = %d\n", t2);
}

