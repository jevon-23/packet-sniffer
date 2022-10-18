#include <float.h>
#include <netinet/in.h>
#include <pcap.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

// void run_server() {
//   char errbuf[PCAP_ERRBUF_SIZE];
//   pcap_if_t *interfaces, *temp;
// 
//   int i = 0;
//   if (pcap_findalldevs(&interfaces, errbuf) == -1) {
//     printf("error in findalldevls\n:");
//     exit(-1);
//   }
// 
//   return;
// }

int processCLI(int argc, char **argv, char **filename) {
  if (argc != 2) {
    printf("usage:");
    exit(-1);
  }
  return 0;
}

int main(int arg, char *argv[]) {
  printf("Successful build!\n");
  return 0;
}
