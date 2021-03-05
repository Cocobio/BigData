#!/bin/sh
if [ $# != 2 ]
then
	echo Insert a file_path and a dectory to save results.
	exit 0
else
	F=$1
	D=$2
fi

mkdir -p $D

# HyperLogLog
#     program      opt f  kmer b   txt
nohup ./cardinal.o -hll $F 20 10 > $D/ERR626208_20_hyperloglog_10.txt &
nohup ./cardinal.o -hll $F 20 15 > $D/ERR626208_20_hyperloglog_15.txt &
nohup ./cardinal.o -hll $F 20 20 > $D/ERR626208_20_hyperloglog_20.txt &
nohup ./cardinal.o -hll $F 20 25 > $D/ERR626208_20_hyperloglog_25.txt &

nohup ./cardinal.o -hll $F 30 10 > $D/ERR626208_30_hyperloglog_10.txt &
nohup ./cardinal.o -hll $F 30 15 > $D/ERR626208_30_hyperloglog_15.txt &
nohup ./cardinal.o -hll $F 30 20 > $D/ERR626208_30_hyperloglog_20.txt &
nohup ./cardinal.o -hll $F 30 25 > $D/ERR626208_30_hyperloglog_25.txt &

nohup ./cardinal.o -hll $F 40 10 > $D/ERR626208_40_hyperloglog_10.txt &
nohup ./cardinal.o -hll $F 40 15 > $D/ERR626208_40_hyperloglog_15.txt &
nohup ./cardinal.o -hll $F 40 20 > $D/ERR626208_40_hyperloglog_20.txt &
nohup ./cardinal.o -hll $F 40 25 > $D/ERR626208_40_hyperloglog_25.txt &