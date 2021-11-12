# Battleship

Simple console PvE game written in C++.

![](https://i.imgur.com/zBY2mtu.png)


### Rules

There are 10 ships:

- One 4-masted
- Two 3-masted
- Three 2-masted
- Four 1-masted

All ships are randomly placed on both boards. The only rule is that the ships cannot touch each other.
Correct shot consists of a letter from `a` to `j` and a number from `1` to `10`, e.g. `a5` or `g10`. **Input a shot with uppercase will cause an error**.
After each hit, player can continue shooting.

![](https://i.imgur.com/UPduNRw.png)

The same goes for computer. When player misses, computer starts shooting.
Player wins when he shoots down all enemy ships.
