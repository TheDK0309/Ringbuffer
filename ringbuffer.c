#include "ringbuffer.h"
#include <stdio.h>
void init_buffer(struct buffer_type *b, unsigned char *buffer){
	b->head=buffer;
    b->tail=buffer;
    b->buffer=buffer;
	
}
void empty_buffer(struct buffer_type *b){
	b->head=b->tail;
	
}
unsigned int get_buffer_status(struct buffer_type b, int *err){
	if( b.head == b.tail )
	{
		*err = 2;
	}
	else if (((b.head-b.buffer)+1)  % MAX_BUFFER == (b.tail-b.buffer))
    {
        *err = 4;
    }
	else if(b.tail>( b.buffer+ MAX_BUFFER )|| b.tail<(b.buffer-1)||b.head>(b.buffer+MAX_BUFFER)||b.head<( b.buffer-1)  )
	{
		*err = 5;
	}
	else
	{
		*err = 0;
	}
	return *err;
}

int add_char_to_buffer(struct buffer_type *b, unsigned char c, int *err){
	*b->head=c;
	b->head=(b->head+1);
	if (((b->head - b->buffer)+1) % MAX_BUFFER== (b->tail-b->buffer))
    {
        *err = 4;
    }
	if(b->head-b->buffer==MAX_BUFFER )
    {
        b->head = b->buffer;
    }
	int x=b->head-b->buffer;
	int y=b->tail-b->buffer;
	if(x>y) return x-y;
	else return MAX_BUFFER-y+x;
}
unsigned char get_char_from_buffer(struct buffer_type *b, int *err)
{
	unsigned char x= *b->tail;
	b->tail=(b->tail+1) ;
	if(b->head==b->tail){
		*err=2;
	}
	if( b->tail - b->buffer == MAX_BUFFER)
	{
		b->tail = b->buffer;
	}
	return x;
}
int print_buffer(struct buffer_type *b, int *err){
	int i,z;
	unsigned char *t;
	int x=(b->head)-(b->buffer);
	int y=(b->tail)-(b->buffer);
	if(x>y) z=x-y;
	else z=MAX_BUFFER-y+x;
	//if b->head>b->tail
	for(t=b->tail;t<b->head;i++){
		printf("Elements inside ring buffer: %c\n",*t);
		t++;
	}
	
	return z;
}
int add_string_to_buffer(struct buffer_type *b, unsigned char *s, int *err){
	int i=0/*taken spaces in buffer*/,z=0/*free spaces in buffer*/,t=0;
	int x=(b->head)-(b->buffer);
	int y=(b->tail)-(b->buffer);
	if(x==y) z=MAX_BUFFER;
	if(x>y) i=x-y;
	else i=MAX_BUFFER-y+x;
	z=MAX_BUFFER-i;
	if (((b->head - b->buffer)+1)  % MAX_BUFFER == (b->tail-b->buffer))
    {
        *err = 4;
    }
	if(b->head-b->buffer==MAX_BUFFER )
    {
        b->head = b->buffer;
    }
	while (s[t] != '\0')
	{
		t ++;
	}
	if(t<=z){
		while (*s!= '\0'){
			add_char_to_buffer(b, *s, err);
			s++;
		}
	}
	return t;
	
}
int get_string_from_buffer(struct buffer_type *b, unsigned char *dest, int len, int *err){
	int i=0;
	while(i<len){
		*dest=*b->tail;
		b->tail+=1;
		i++;
		dest++;
	}
	if(b->head==b->tail){
		*err=2;
	}
	if( b->tail - b->buffer == MAX_BUFFER)
	{
		b->tail = b->buffer;
	}
	return i;
}
	/*
	int i=0,z=0,t=0;
	int x=(b->head)-(b->buffer);
	int y=(b->tail)-(b->buffer);
	if(x==y) z=MAX_BUFFER;
	if(x>y) i=x-y;
	else i=MAX_BUFFER-y+x;
	z=MAX_BUFFER-i;
	if(b->head==b->tail){
		*err=2;
	}
	while(dest[t]!='\0'){
		t++;
	}
	if(t<i){
		while (*dest!= '\0'){
			dest=*b->tail;
			b->tail=(b->tail+1);
			len++;
		}
	}
	return len;
	
	unsigned char x= *b->tail;
	b->tail=(b->tail+1) ;
	if(b->head==b->tail){
		*err=2;
	}
	if( b->tail - b->buffer == MAX_BUFFER )
		{
			b->tail = b->buffer;
		}
	return x;
	
}*/