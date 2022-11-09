#include<stdio.h>
int n, nf, in[100], p[50], hit = 0;
int i, j, k, pgfaultcnt = 0;

void getData() {
	printf("\nEnter length of page reference sequence: ");
	scanf("%d", &n);
	printf("\nEnter the page reference sequence: ");
	for(i=0; i<n; i++) scanf("%d", &in[i]);
	printf("\nEnter no of frames: ");
	scanf("%d", &nf);
}

void init() {
	pgfaultcnt = 0;
	for(i=0; i<nf; i++) p[i] = 9999;
}

int isHit(int data) {
	hit = 0;
	for(j=0; j<nf; j++) {
		if(p[j] == data) {
			hit = 1;
			break;		
		}
	}
	return hit;
}

int getHitIndex(int data) {
	int hitind;
	for(k=0; k<nf; k++) {
		if(p[k] == data) {
			hitind = k;
			break;
		}
	}
	return hitind;
}

void disPages() {
	for(k=0; k<nf; k++) {
		if(p[k]!=9999) printf(" %d", p[k]);
	}
}

void dispPgFaultCnt() {
	printf("\nTotal no of page faults:%d", pgfaultcnt);
	printf("\n");
}

void fifo() {
	init();
	for(i=0; i<n; i++) {
		printf("\nFor %d :", in[i]);
		if(isHit(in[i]) == 0) {
		for(k=0; k<nf-1; k++) p[k] = p[k+1];
			p[k] = in[i];
			pgfaultcnt++;
			disPages();
		}
		else printf("Page hit");
	}
	dispPgFaultCnt();
}

void optimal() {
	init();
	int near[50];
	for(i=0; i<n; i++) {
		printf("\nFor %d :", in[i]);
		if(isHit(in[i]) == 0) {
			for(j=0; j<nf; j++) {
				int pg = p[j];
				int found = 0;
				for(k=i; k<n; k++) {
					if(pg == in[k]) {
						near[j] = k;
						found = 1;
						break;
					}
					else found = 0;
				}	
				if(!found) near[j] = 9999;
			}
			int max = -9999;
			int repindex;
			for(j=0; j<nf; j++) {
				if(near[j] > max) {
					max = near[j];
					repindex = j;
				}
			}
			p[repindex] = in[i];
			pgfaultcnt++;
			disPages();
		}
		else printf("Page hit");
	}
	dispPgFaultCnt();
}

void lru() {
	init();
	int least[50];
	for(i=0; i<n; i++) {
		printf("\nFor %d :", in[i]);
		if(isHit(in[i]) == 0) {
			for(j=0; j<nf; j++) {
				int pg = p[j];
				int found = 0;
				for(k=i-1; k>=0; k--) {
					if(pg == in[k]) {
						least[j] = k;
						found = 1;
						break;
					}
					else found = 0;
				}
				if(!found) least[j] = -9999;
			}
			int min = 9999;
			int repindex;
			for(j=0; j<nf; j++) {
				if(least[j] < min) {
					min = least[j];
					repindex = j;
				}
			}	
			p[repindex] = in[i];
			pgfaultcnt++;
			disPages();
		}
		else printf("Page hit");
	}
	dispPgFaultCnt();
}

int main() {
	int choice;
	while(1) {
		printf("\nPage Replacement Algorithms \n1.Enter data \n2.FIFO \n3.Optimal \n4.LRU \n5.Exit \nEnter your choice:");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				getData();
				break;
			case 2:
				fifo();
				break;
			case 3:
				optimal();
				break;
			case 4:
				lru();
				break;
			default:
				return 0;
				break;
		}
	}
	return 0;
}

