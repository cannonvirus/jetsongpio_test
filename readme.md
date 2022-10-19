# Jetson Xavier GPOI Test
## Compiler
```bash
# gcc9.4 (c++17)
```

## Docker runfile option
```bash
--runtime=nvidia --gpus all
-v /sys/devices/:/sys/devices/ \
-v /sys/class/gpio:/sys/class/gpio
```

## In Docker Setting
```bash
# https://github.com/pjueon/JetsonGPIO
cd /
git clone https://github.com/pjueon/JetsonGPIO
cd JetsonGPIO
mkdir build && cd build
cmake ..
make install

nano ~/.bashrc
#-----
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
#-----
source ~/.bashrc
ldconfig
```

