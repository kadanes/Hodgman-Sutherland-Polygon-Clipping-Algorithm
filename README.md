# Hodgman-Sutherland-Polygon-Filling-Algorithm
This is an implementation of Hodgman Sutherland polygon clipping algorithm using graphics.h in c. 
<hr>
##### The current polygon points have been hardcoded

You can take the input from user and store it in the point struct.
Don't forgert to innitialize the "innitialPointCount" to number of points. 
Also ensure that the points are stored in cyclic manner.
<hr>
##### Need help with using graphics.h?

>Mirrored from https://chahalgurpinder95.wordpress.com/2013/10/12/install-graphics-h-in-ubuntu/

For using graphics.h library in Ubuntu, you need to follow few simple steps given below:

First of all, you need to install few packages. For that, run command this on your terminal “sudo apt-get install libsdl-image1.2 libsdl-image1.2-dev guile-1.8 guile-1.8-dev”

Next you need to install libgraph package. Download libgraph-1.0.2.tar.gz from link:

download.savannah.gnu.org/releases/libgraph/libgraph-1.0.2.tar.gz
( Does not work. Find the library on the internet. With anyluck it will already be downloaded on your pc.)

Extract this where you want. Now navigate to the folder, where you just extracted your libgraph-1.0.2.tar.gz using cd command. Run these commands on your terminal.

> cd libgraph-1.0.2
> ./configure
>sudo make
> sudo make install
> sudo cp /usr/local/lib/libgraph.* /usr/lib

And if you got error message “configure: error: *** SDL version 1.2.0 not found!”, try installing it using: “sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev”

Another error which you can get is: “configure: cannot find guile-config; is Guile installed?” Solve this by using command“sudo apt-get install guile guile-dev”.

If this didn’t helped much, then we have another way to get it work in right way. Use synaptic package manager to install related files.


