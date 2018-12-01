#############################################################################
#                                                                           #
#                 COPYRIGHT (C)  2011    ELUON, INC.                        #
#                                                                           #
#  All rights reserved. ELUON, Inc. source code is an unpublished work and  #
#  the use of a copyright notice does not imply otherwise.  This source     #
#  code contains confidential, trade secret material of ELUON, Inc. Any     #
#  attempt or participation in deciphering, decoding, everse engineering    #
#  or in any way altering the source code, is strictly prohibited, unless   #
#  the prior written consent of ELUON, Inc. is obtained.                    #
#                                                                           #
#############################################################################


INC			= -I. -I./include -I/usr/local/include 
LIB			= -L/usr/local/lib -L../lib
OUT			= bin

LOPTS		= 

LFLAGS		= -w -Wall -lrt -lpthread -lnsl -lsqlite3 $(LOPTS)

CFILES		= main.cpp 	\
			  util.cpp	\

OBJS    = $(CFILES:.cpp=.o)

CC		= g++

.SUFFIXES : .cpp .o

.cpp.o    : $(CFILES)	
	$(CC) -g -c -w  $(CFLAGS) $*.cpp

binary	: $(OBJS)
	$(CC) -o $(OUT) $(OBJS)  $(LFLAGS)

clean   ::
	rm -f $(OBJS) $(OUT)

