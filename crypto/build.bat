adb push libs\\armeabi\\functions /data/local/tmp/
adb shell chmod 755 /data/local/tmp/functions
adb shell /data/local/tmp/functions "http://shouji.360tpcdn.com/150513/4dfdf1ab2858f0a287cfe681cbdd9c2c/com.qihoo.haosou_331.apk"
ndk-build