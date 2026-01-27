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
layout: center
---

# How the web works

---

## Clients and servers

The core parts of the web are computers either called **clients** or **servers**.

<img class="mx-auto rounded w-1/3" src="./images/06/client_server.png"/>

They are **both** computers, and can both be clients and servers at the same time. 

But for the purposes of this course, we'll treat them as static states

---

## Client Server Interaction

<img class="mx-auto rounded w-1/3" src="./images/06/client_server.png"/>

1. The client sends a **request** to the server
    - usually by using a piece of software called a **web browser**
2. The server receives the request,
    - note that a server is simply a computer
    - in that computer there exists files
    - when the server receives a request, it finds the requested file
    - then it **responds** to the client with the file
3. The client **receives** the response
    - then the **web browser** displays the file to the user

> try ctrl + s

---

## Other Tools Needed in the Web

If we imagine the internet as a road, 

- and on one end we have the **client** (your house)
- and on another end, we have the **server** (a shop)

To get **data** (goods) from the server (shop) to the client (your house), we need a few things:
1. The road itself (*internet*)
2. the transport mechanism, like walking, biking, driving (*TCP/IP*)
3. The address of the destination (*DNS*)
4. The language we use to ask for the goods (*HTTP/HTTPS*)
5. The goods themselves (*files*)

---

## TCP IP

Transmission Control Protocol / Internet Protocol is a **protocol** that defines how data is sent and received over the internet.

It guarantees that data sent from one computer to another arrives intact and in the correct order.

---

## DNS

Domain Name System is like the phonebook of the internet.

It translates human-friendly domain names (like www.example.com) into IP addresses (like `142.250.190.78`)

A DNS is already built into your operating system and web browser, so you don't have to worry about it.

It's basically a website that tells your browser where to find other websites.

---

## HTTP

Hypertext Transfer Protocol is the protocol used for transferring web pages on the internet.

When you type a URL into your web browser, it sends an HTTP request to the server hosting that website.

This request is the **format** that both the client and server understand to communicate.

It includes information like:
- the method (GET, POST, etc)
- headers (metadata about the request)
- body (data being sent, if any)

---
layout: center
---

## So what happens exactly?

---

1. You type in a URL in your web browser

Your browser then goes to a **DNS server** to find the IP address of the server that hosts the website

2. The browser gets that IP address back, then it sends an **HTTP request** to that IP address

When it's being sent along, it's using the **TCP/IP** protocol to get there

3. The server then responds with a 200 OK, 

Meaning that file exists and you can look at it, 

Then starts sending the website's file back to your browser in small chunks called packets

4. The browser assembles those small chunks into a complete page and displays it to you

---

# Case Study
Instapay

---

## QR PH

a national standardized qr system mandated by **Bangko Sentral ng Pilipinas**

This is the **LOOK** of the QR, and this standard allows **interoperability** between different banks and payment service providers

## Instapay

Is a real-time fund transfer service owned by **BancNet**

---

## What happens

When you scan the QR code using your bank's mobile app,

It reads the data encoded in the QR code, which contains:
- the recipient's bank information
- the amount to be transferred
- a reference note
- etc

Then your bank's app sends an **HTTP request** to BancNet's server to initiate the transfer, **with** that information

BancNet's server then processes the request, verifies the details, and initiates the fund transfer between the banks involved.

Then BancNet's server responds back to your bank's app with a confirmation of the transaction status

Then your bank's app displays the confirmation to you

---

1. send
2. receive
3. status
4. process
5. respond
6. display
