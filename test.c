#include <gtest/gtest.h> 
#include <stdio.h> 
#include "ringbuffer.h"

TEST(AddchartoBuffer,test1)
{

    unsigned char rx_buffer[MAX_BUFFER];
    struct buffer_type r;
    init_buffer(&r, rx_buffer);
    int err = 0;
    EXPECT_EQ(1, add_char_to_buffer( &r, '1', &err) );
}
TEST(AddchartoBuffer,test2)
{

    unsigned char rx_buffer[MAX_BUFFER];
    struct buffer_type r;
	int err=0;
    init_buffer(&r, rx_buffer);
    add_char_to_buffer( &r, '1', &err);
    add_char_to_buffer( &r, 'A', &err);
    add_char_to_buffer( &r, 'B', &err);
    add_char_to_buffer( &r, 'c', &err);
    add_char_to_buffer( &r, '.', &err);
	
	EXPECT_EQ(0,err);
	EXPECT_EQ(6, add_char_to_buffer( &r, '5', &err) );
   }

TEST(InitializeBuffer, Initialize_empty)
{

    unsigned char rx_buffer[MAX_BUFFER];
    struct buffer_type r;
    int err = 0;

    init_buffer(&r, rx_buffer);

    EXPECT_TRUE(r.head == rx_buffer);
    EXPECT_TRUE(r.tail == rx_buffer);
    EXPECT_TRUE(r.buffer == rx_buffer);
}

TEST(InitializeBuffer, Initialize_with_string)
{

    unsigned char rx_buffer[MAX_BUFFER] = "Hello world!";
    struct buffer_type r;
    int err = 0;

    init_buffer(&r, rx_buffer);

    EXPECT_TRUE(r.head == rx_buffer);
    EXPECT_TRUE(r.tail == rx_buffer);
    EXPECT_TRUE(r.buffer == rx_buffer);
}

TEST(GetBufferStatus, EmptyBuffer) {
  unsigned char rx_buffer[MAX_BUFFER];
  struct buffer_type r;
  int err=0;

  init_buffer(&r, rx_buffer);
  int status = get_buffer_status(r, &err);
  EXPECT_EQ(2, status);
  EXPECT_EQ(2, err);
}
TEST(GetBufferStatus, String) {
	unsigned char rx_buffer[MAX_BUFFER] = "Hello world!";
	struct buffer_type r;
	int err = 0;

	init_buffer(&r, rx_buffer);
	EXPECT_EQ(err,0);
}
TEST(GetCharFromBuffer,CHAR){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	int err = 0;
	init_buffer(&r, rx_buffer);
	add_char_to_buffer( &r, '1', &err);
	
    unsigned char x= get_char_from_buffer(&r, &err);
	EXPECT_EQ('1',x);
	EXPECT_EQ(2,err);
}
TEST(GetCharFromBuffer,CHAR2){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	int err = 0;
	init_buffer(&r, rx_buffer);
	add_char_to_buffer( &r, '1', &err);
	add_char_to_buffer( &r, '2', &err);
	add_char_to_buffer( &r, '3', &err);
    unsigned char x= get_char_from_buffer(&r, &err);
	unsigned char y= get_char_from_buffer(&r, &err);
	EXPECT_EQ('1',x);
	EXPECT_EQ('2',y);
	EXPECT_EQ(0,err);
}
TEST(GetCharFromBuffer,CHAR3){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	int err = 0;
	init_buffer(&r, rx_buffer);
	add_char_to_buffer( &r, '1', &err);
	add_char_to_buffer( &r, 'X', &err);
	add_char_to_buffer( &r, ' ', &err);
    unsigned char x= get_char_from_buffer(&r, &err);
	unsigned char y= get_char_from_buffer(&r, &err);
	unsigned char z= get_char_from_buffer(&r, &err);
	EXPECT_EQ('1',x);
	EXPECT_EQ('X',y);
	EXPECT_EQ(' ',z);
	EXPECT_EQ(2,err);
}
TEST(print,test1){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	int err = 0;
	init_buffer(&r, rx_buffer);
	add_char_to_buffer( &r, '1', &err);
	add_char_to_buffer( &r, '2', &err);
	int x=print_buffer( &r, &err);
	EXPECT_EQ(2,x);
	EXPECT_EQ(0,err);
}
TEST(print,test2){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	int err = 0;
	init_buffer(&r, rx_buffer);
	add_char_to_buffer( &r, '1', &err);
	add_char_to_buffer( &r, '2', &err);
	add_char_to_buffer( &r, '3', &err);
	add_char_to_buffer( &r, '4', &err);
	add_char_to_buffer( &r, '5', &err);
	int x=print_buffer( &r, &err);
	EXPECT_EQ(5,x);
	EXPECT_EQ(0,err);
}
TEST(print,test3){
	unsigned char rx_buffer[MAX_BUFFER];
	struct buffer_type r;
	int err = 0;
	init_buffer(&r, rx_buffer);
	add_char_to_buffer( &r, '1', &err);
	add_char_to_buffer( &r, ' ', &err);
	add_char_to_buffer( &r, 'a', &err);
	add_char_to_buffer( &r, 'B', &err);
	add_char_to_buffer( &r, '.', &err);
	get_char_from_buffer(&r,&err);
	int x=print_buffer(&r, &err);
	EXPECT_EQ(4,x);
	EXPECT_EQ(0,err);
}
TEST(addString,test1){
	unsigned char rx_buffer[MAX_BUFFER]="1111111";
    struct buffer_type r;
    init_buffer(&r, rx_buffer);

    int err = 0;
    EXPECT_EQ(7,add_string_to_buffer( &r, rx_buffer , &err) );
	EXPECT_EQ(0,err);
}
TEST(addString,test2){
	unsigned char rx_buffer[MAX_BUFFER]="1111111";
	unsigned char rx_buffer1[MAX_BUFFER]="Abc  ươ.;";
    struct buffer_type r;
    init_buffer(&r, rx_buffer);
	
    int err = 0;
    EXPECT_EQ(7,add_string_to_buffer( &r, rx_buffer , &err) );
	EXPECT_EQ(11,add_string_to_buffer( &r, rx_buffer1 , &err) ) ;
	EXPECT_EQ(0,err);
}
TEST(GetString,test){
	unsigned char rx_buffer[MAX_BUFFER]="1111111";
	struct buffer_type r;
    init_buffer(&r, rx_buffer);
	init_buffer(&r, rx_buffer);
	int err = 0;
	add_string_to_buffer( &r, rx_buffer , &err);
	int x=get_string_from_buffer(&r,rx_buffer,4,&err);
	print_buffer(&r,&err);
	EXPECT_EQ(0,err);
	EXPECT_EQ(4,x);
}
