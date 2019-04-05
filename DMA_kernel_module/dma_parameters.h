/* This header file is shared between the DMA Proxy test application and the DMA Proxy device driver. It defines the
 * shared interface to allow DMA transfers to be done from user space.
 *
 * Note: the buffer in the data structure should be 1st in the channel interface so that the buffer is cached aligned,
 * otherwise there may be issues when using cached memory. The issues were typically the 1st 32 bytes of the buffer
 * not working in the driver test.
 */

#define TEST_SIZE (500 * 720 * 107 * 2)
#define SEND_PHYS_ADDR 0x09000000
#define RECIEVE_PHYS_ADDR 0x0ffff000
#define  DEVICE_NAME "cubedma"    ///< The device will appear at /dev/ebbchar using this value
#define  CLASS_NAME  "dma"        ///< The device class -- this is a character device driver

struct dma_data {
	uint16_t buffer[TEST_SIZE];
	unsigned int length;
};