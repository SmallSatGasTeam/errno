#ifndef RADIO_H
#define RADIO_H


class Radio{
	private:
		//file descriptor
		int fd;
	public:
	Radio(char* device = "radio1", int baud = 9600);
	~Radio();
	void pushTx(char* telem);

};

#endif
