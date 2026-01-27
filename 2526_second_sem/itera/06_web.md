---
title: 06 Web Technologies
exportFilename: exports/itera/06_web
lineNumbers: true
---

# How the internet works

---

## History of the Internet

The internet start at around the 1960s from a US-army-funded research project which evolved into public infrastructure in the 1980s.

The way it works hasn't changed much since then.

<img class="mx-auto rounded w-2/4" src="./images/06/arpanet.png"/>

---

## A simple network

When two computers need to communicate, we need to link them, either **physically** or **wirelessly**.

<img class="mx-auto rounded w-1/3" src="./images/06/simple_network.png"/>

You can now send data between the two computers.

---

## A "simple" Network

And you can simply connect as many computers as you want in a network.

<img class="mx-auto rounded w-1/3" src="./images/06/complex_network.png"/>

---

## Network Switch

To solve this problem, we use a **network switch**.

<img class="mx-auto rounded w-1/3" src="./images/06/network_switch.png"/>

A **network switch** is a special computer that acts like a traffic controller.

So to send a message from A to B, then A sends the message to the switch, and the switch forwards it to B.

---

## A network of networks

A single network switch can only scale so much, so if we wanted to connect even more computers, we simply **connect computers again**

> A network switch is a computer, so we can connect it to other network switches.

<img class="mx-auto rounded w-1/3 mt-4" src="./images/06/network_of_networks.png"/>

---

## Even more networks

<img class="mx-auto rounded w-1/3" src="./images/06/big_network.png"/>

In reality, this approach to connecting computers present two major problems:
1. latency
2. failure points

---

## Routers

<img class="mx-auto rounded w-1/3" src="./images/06/router.png"/>

To solve this we connect a **local** network (meaning computers from one switch) using something called a **router**

The router acts like a post office, it's main job is to send messages between networks (between other routers).

When a computer sends the router a message, the router reads the address of the destination computer, and decides the best way to send the message.

This is **close** to how the internet works

---
layout: two-cols-header
---

## Modem

::left::
Now all we need to do is to connect all our routers, this infrastructure already exists

So we connect our local network to a **modem** which connects to the internet service provider (**ISP**) infrastructure.

<small>(note that most commercial routers is usually a combination of a network switch, a router and a modem)</small>

And the ISP have access to all the other routers connected to their infrastructure

**But** it can also access other ISPs infrastructure

::right::
<img class="mx-auto rounded w-1/4" src="./images/06/isp.png"/>

---

## Finding computers

To send a message to another computer, you have to specify its **address**.

This is called an **IP address** (Internet Protocol address).

It's a series of numbers and dots that uniquely identifies a computer on the internet.

```
192.0.2.172
```

Try out
```
142.250.190.78
```

---

## The internet vs The web

The internet is the **infrastructure** that connects computers together.

The web is a **service** that runs on top of the internet.

---

# How the web works

---

## Clients and servers

---

## Tools

1. internet connection
2. transmission control protocol/internet protocol (TCP/IP)
3. domain name system
4. hypertext transfer protocol (HTTP/HTTPS)
5. files

---
layout: center
---

## What happens when you type a URL into your browser?

---

## What happens exactly?

---

## DNS

---

## Packets

---

## Basics of HTTP
