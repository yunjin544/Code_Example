### C++ Projcet Template by Cmake for Pinocchio

Code Reference : https://gepettoweb.laas.fr/doc/stack-of-tasks/pinocchio/master/doxygen-html/index.html

How to install Pinocchio : https://stack-of-tasks.github.io/pinocchio/download.html (Option : Build from Source file & Disable Python interface )

1. Change Directory 
```bash
cd {pinocchio_Example_PATH}
```

2. Generate Makefile  ( or Ninja )
Make user :
```bash
mkdir build & cd build & cmake ..
```
( Optional )Ninja user:
```bash
mkdir build & cd build & cmake .. -G Ninja
```

4. Build your Program/Example!
Make user :
```bash
make
```
( Optional )Ninja user:
```bash
ninja
```

4. Test your Program/Example!




Option: Install Ninja Build tool ( Fast build tool )
```bash
sudo apt-get update -y & sudo apt-get install -y ninja-build

```




