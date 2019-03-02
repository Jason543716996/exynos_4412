if [ -z $1 ]
then
    echo "usage: ./sd_fusing.sh <SD Reader's device file>"
    exit 0
fi

if [ -b $1 ]
then
    echo "$1 reader is identified."
else
    echo "$1 is NOT identified."
    exit 0
fi

####################################
#<verify device>

BDEV_NAME=`basename $1`
BDEV_SIZE=`cat /sys/block/${BDEV_NAME}/size`

if [ ${BDEV_SIZE} -le 0 ]; then
	echo "Error: NO media found in card reader."
	exit 1
fi

if [ ${BDEV_SIZE} -gt 32000000 ]; then
	echo "Error: Block device size (${BDEV_SIZE}) is too large"
	exit 1
fi

####################################
# check files

E4412_PROJ=./arm.bin
#MKBL2=../mkbl2

if [ ! -f ${E4412_PROJ} ]; then
	echo "Error: u-boot.bin NOT found, please build it & try again."
	exit -1
fi

#<make bl2>
#${MKBL2} ${E4412_PROJ} bl2.bin 14336

####################################
# fusing images

signed_bl1_position=1
bl2_position=17
proj_position=49
tzsw_position=705

#<BL1 fusing>
echo "---------------------------------------"
echo "BL1 fusing"
dd iflag=dsync oflag=dsync if=./E4412_N.bl1.bin of=$1 seek=$signed_bl1_position

#<BL2 fusing>
echo "---------------------------------------"
echo "BL2 fusing"
dd iflag=dsync oflag=dsync if=./bl2.bin of=$1 seek=$bl2_position

#<u-boot fusing>
echo "---------------------------------------"
echo "proj: arm.bin fusing"
dd iflag=dsync oflag=dsync if=${E4412_PROJ} of=$1 seek=$proj_position

#<TrustZone S/W fusing>
#echo "---------------------------------------"
#echo "TrustZone S/W fusing"
#dd iflag=dsync oflag=dsync if=./E4412_tzsw.bin of=$1 seek=$tzsw_position

#<flush to disk>
sync

####################################
#<Message Display>
echo "---------------------------------------"
echo "project code arm.bin is fused successfully."
echo "Eject SD card and insert it again."

