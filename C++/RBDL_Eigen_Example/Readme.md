# Eigen3 & RBDL example
RDBL Version : 3.1.3 ( URDF Reader ON)
> RBDL-ORB : https://github.com/ORB-HD/rbdl-orb

Eigen3 Version : 3.3
> Eigen3 :https://eigen.tuxfamily.org/index.php?title=Main_Page

This Repository is exmples of RBDL & Eigen3 for Korean user.

Build Tool : Cmake & Make ( Optional : Ninja )

1. Install Build Tool
<pre><code>sudo apt install cmake</code></pre> 
<pre><code>sudo apt-get install build-essential</code></pre> 

2. Install Eigen3
<pre><code>sudo apt install libeigen3-dev</code></pre> 

4. Build & install RBDL
> https://github.com/ORB-HD/rbdl-orb (For your reference)  
  
  
5. Download this Repository
<pre><code>git clone https://github.com/yunjin544/Code_Example.git </code></pre> 

6. Build this Project
<pre><code>cd Code_Example/C++/RBDL_Eigen_Example </code></pre> 
<pre><code>mkdir build </code></pre> 
<pre><code>cd build && cmake .. </code></pre> 
<pre><code>make </code></pre> 
<pre><code>cd example </code></pre> 

7. You can Run Example Programs!
