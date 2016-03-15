/*
 *  Created on: Dec 22, 2014
 *      Author: yes
		hello
		mor
		check
 */


extern "C" {

#include "rule_engine/buffered_reader.h"
#include "stats.h"
extern stats_t* stats;

extern int globInd;
extern const uint8* globBuf;
extern size_t globBufSize;

}


class BufferReaderTest : public ::testing::Test {
protected:
	virtual void SetUp() {
		char arr[260] = {0};
		initBR((uint8*)arr, 260);
	}
	virtual void TearDown() {
		// Nothing
	}

};

TEST_F(BufferReaderTest, readStringBR) {

	char buff[260];
	char arr[10] = {'a','b','\0'};
	initBR((uint8*)arr, 10);
	
	ASSERT_TRUE(3 == readStringBR(buff, 260));
	initBR((uint8*)arr, 10);
	ASSERT_TRUE(2 == readStringBR(buff, 2));
	initBR((uint8*)arr, 2);
	ASSERT_TRUE(2 == readStringBR(buff, 2));
	initBR((uint8*)arr, 10);
	ASSERT_TRUE(0 == readStringBR(NULL, 0));
	
	arr[0] = 'a';
	arr[1] = NULL;
	arr[2] = 'b';	
	initBR((uint8*)arr, 10);
	
	ASSERT_TRUE(2 == readStringBR(buff, 260));
	
	globInd = globBufSize;
	ASSERT_TRUE(0 == readStringBR(buff, 4));	
	
}

TEST_F(BufferReaderTest, readBytesBR) {

	char buff[260];
	ASSERT_TRUE(7 == readBytesBR(buff, 1, 7));

	ASSERT_TRUE(0 == readBytesBR(buff, 1, 261));
	
	printf("*****TODO: there is a bug in the code where we get NULL and still returning the size we wanted to read and progress counter***************");
	//EXPECT_TRUE(0 == readBytesBR(NULL, 1, 2)); //TODO: there is a bug in the code where we get NULL and still returning the size we wanted to read and progress counter
	
}
