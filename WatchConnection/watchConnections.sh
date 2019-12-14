#! /bin/bash
#cd ~
if [ -n "$1"]
then
	echo "ok"
	watch -d -n 1 "/home/student/Desktop/WatchConnection/pingArpClients.sh"
else
	watch -d -n 1 "/home/student/Desktop/WatchConnection/pingArpClients.sh"
fi
