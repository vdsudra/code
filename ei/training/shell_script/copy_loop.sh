for i in 01_2016 02_2016 03_2016 04_2016 04_2016 05_2016 07_2016 08_2016 09_2016 10_2016
do
cp -r /media/mmcblk0/3rdeye/storage/11_10_2016 /media/mmcblk0/3rdeye/storage/10_$i
done

cat /media/mmcblk0/3rdeye/storage/oldest.json ; echo; cat /media/mmcblk1/3rdeye/storage/oldest.json
