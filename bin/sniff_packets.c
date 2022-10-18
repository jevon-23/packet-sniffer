/* SNIFF_PACKETS.C 
 *
 * Binary file who's job is to read packets in and parse them out.
 * Not sure what exactly to do with them, but eventually I want this
 * To somehow be a receive and response
 *
 * Note: One packet is not going to be enough to get everything
 *       But maybe one thing that would be interesting would be 
 *       to put packets together myself in order to build out everything
 *
 * Credit for starter code using pacp to read sockets: 
 *    "binarytides.com/packet-sniffer-code-c-libpcap-linux-sockets"
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>
#include <pcap.h>
#include <sys/socket.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer) {
    int size = header->len;
    /* TODO: 
     *    1. Determine the type of packet that we are receieing
     *      2. ethernet? tcp? udp? arp? etc.
     *
     *    2. Parse out the data in the packet and print out the data
     *       in a formatted fashion. 
     */
    printf("Header packet size = %d\n", size);
}


// credit: "binarytides.com/packet-sniffer-code-c-libpcap-linux-sockets" 
void start_sniff() {
    pcap_if_t *alldevsp, *device;
    char errbuf[100], devs[100][100];

    /* Get the list of availble devices */
    printf("Searching for vailable devs: \n");
    if (pcap_findalldevs(&alldevsp, errbuf) ) {
        printf("Error finding the devices\n");
        exit(-1);
    }

    /* Print out all of the devices, and put their names in a list
     * for future usage
     */
    printf("Done searching for devices. Available devices are:\n");
    int count = 0;
    for (device = alldevsp; device != NULL; device = device->next,
            count++) {
        printf("%d. %s - %s\n", count, device->name, device->description);

        if (device->name != NULL) {
            strcpy(devs[count], device->name);
        }
    }

    /* Ask user which device they would like to open */
    int n;
    printf("Which device would you like to sniff: \n");
    scanf("%d", &n);
    char *dev_name = devs[n];

    // Open device for sniffing
    printf("Opening device: %s\n", dev_name);
    pcap_t *handle = pcap_open_live(dev_name, 65536, 1, 0, errbuf);
    if (handle == NULL) {
        printf("Could not open device %s: %s \n", dev_name, errbuf);
        exit(-1);
    }

    printf("Opened device, beginning to sniff \n");
    pcap_loop(handle, 2, process_packet, NULL);
}

int processCLI(int argc, char **argv, char **filename) {
  if (argc != 2) {
    printf("usage:");
    exit(-1);
  }
  return 0;
}
int main(int arg, char *argv[]) {
    start_sniff();
}
