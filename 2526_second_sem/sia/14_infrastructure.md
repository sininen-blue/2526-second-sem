---
title: 14 Infrastructure
exportFilename: exports/sia/14_infrastructure
lineNumbers: true
---

# Infrastructure

Infrastructure, middleware, and platforms

---

## Infrastructure

The term *infrastructure* serves as a broad, *catch-all* term that encompasses all the underlying systems, hardware, and foundational software sitting *beneath the actual application*. 

Like the supporting structure of a modern city
- plumbing,
- the electrical grid, and
- waste management

In an enterprise software context, infrastructure provides the *raw compute power*, storage capacity, and network routing capabilities *necessary to host code*. 

By **decoupling** the *application layer* from these low-level resources, infrastructure allows software engineers to build features without constantly worrying about the *physical limitations* of the machinery running their code.

---
layout: center
---

# Hardware

---

## Hardware, software, and virtualization

Historically, infrastructure strictly meant **physical hardware** (often referred to as "*bare metal*") which required physical servers, running physical Ethernet cables, and manually configuring hardware firewalls in a climate-controlled data center. 

This paradigm was *costly*, *slow to scale*, and prone to *single points of failure*. 

The industry shifted with the advent of **virtualization**, a technology driven by *hypervisors* that abstracts physical hardware into multiple, isolated Virtual Machines (VMs). 

This allowed enterprise teams to maximize hardware utilization, turning one massive physical server into *dozens of independent virtual ones*. 

This concept has evolved into *software-defined infrastructure*, where networking, storage, and firewalls are no longer managed via physical switches and cables, 

But are instead provisioned instantly through **software commands and configuration files**.

---

## Hybrid cloud

While public cloud providers like Amazon Web Services, Microsoft Azure, and Google Cloud Platform offer massive scalability, the reality for most established enterprises is a *hybrid cloud approach*. 

A hybrid cloud *combines on-premises infrastructure* or private clouds, which enterprises maintain for *legacy systems, compliance, strict data sovereignty laws, or intellectual property protection*

With public cloud resources used for *variable* workloads and consumer-facing applications. 

The core engineering hurdle in a hybrid cloud strategy is achieving seamless integration. 

Data must flow securely and consistently across these distinct environments, requiring robust networking setups, unified security postures, and complex data synchronization mechanisms to ensure that the on-prem systems and cloud instances stay perfectly aligned.

---

## Example

To visualize a modern infrastructure stack, consider the foundational layers required to deploy a standard web application. 

At the baseline is *compute*, 
- which could be *physical servers* in a private data center or *virtualized AWS EC2 instances* in the cloud. 

Next is *storage*, 
- which ranges from *high-speed Storage Area Networks* for relational databases to highly scalable cloud object storage like *Amazon S3* for static assets. 

Connecting these pieces is the *network infrastructure*, 
- which includes *Virtual Private Clouds* (VPCs), *subnets* to isolate private data, *load balancers* to distribute incoming traffic, and *firewalls* to block malicious actors. 

---
layout: center
---

# Middleware

---

## Middleware

If infrastructure is the physical foundation, middleware is the *structural glue* that binds disparate applications, databases, and services together. 

It acts as an intermediary layer that sits squarely in the middle of separate systems, functioning as a *translator* that resolves differences in operating systems, network protocols, and data structures. 

Despite its critical role, "*middleware*" remains an incredibly *vague and malleable* term in software engineering. 

Its exact definition depends almost entirely on the architectural *context* of the conversation and the specific *domain* of the engineer you are talking to, shifting meaning from enterprise data routing to web request handling.

---

## In General

In large-scale enterprise architecture, middleware typically describes 

> Massive, distributed software systems designed to decouple complex applications. 

A prime example is the *message broker* (such as Apache Kafka, RabbitMQ, or IBM MQ) which allows *independent microservices* to communicate asynchronously via message queues rather than direct, brittle HTTP links. 

In this broader context, middleware acts as a *centralized traffic controller*, ensuring that an old billing system can seamlessly exchange data with a modern mobile app without either system needing to understand the other's internal architecture.

---

## In web applications

When working within *web development* frameworks like Express.js, Django, or Laravel, the definition of middleware shrinks down to the *HTTP request-response* pipeline. 

Here, middleware consists of specific code blocks or functions executed sequentially **between the moment** a server receives an HTTP request and the moment it returns a final response to the user. 

This layer handles cross-cutting concerns that shouldn't clutter your core business logic. 

Common responsibilities include 
- *authentication* and *authorization* (intercepting a request to verify a JSON Web Token), 
- *logging* and *telemetry* (tracking request performance), and 
- *security protocols* like CORS configuration or *rate limiting* to shield the backend from automated denial-of-service attacks.

---

## In object relational models

Another classic application of middleware is found in database communication via *Object-Relational Mapping* (ORM) libraries like Hibernate, Prisma, or SQLAlchemy. 

An ORM acts as a *dedicated data-tier middleware* that sits directly between your object-oriented application code and a relational database management system. 

This software layer is designed to solve the notorious Object-Relational Impedance Mismatch, which arises because programming languages organize data into complex object graphs while databases organize data into rigid, flat tables. 

The ORM serves as a translator, automatically converting a developer's object manipulation (like instantiating a new user object) into clean, optimized SQL queries behind the scenes.

---

## In the example of game engines

The concept of middleware takes an interesting linguistic turn within the *gaming industry* and other *software systems*. 

From a pure computer science perspective, a game engine like Unreal or Unity *acts as a form of middleware*, as it sits between the game's core logic and the underlying operating system or low-level graphics APIs like DirectX and Vulkan. 

However, in daily game development jargon, engineers refer to the engine as "the platform" or framework. 

They reserve the word middleware specifically for highly specialized, third-party plug-ins integrated into the engine. 

Examples include 
- Havok or PhysX for advanced physics simulation, 
- Wwise or FMOD for dynamic audio scripting, and 
- SpeedTree for rendering complex vegetation, saving studios from rewriting these highly specialized systems from scratch.

---
layout: center
---

# Platforms

---

## Platforms

A platform represents the *cohesive operational environment* where code actually **executes**. 

A platform sits *on top* of raw infrastructure, but serves as the deployment target *before* you introduce application-specific middleware or logic. 

> Its primary mission is abstraction and standardization. 

By automating 
- server provisioning, 
- operating system patching, and 
- runtime updates, 

A platform completely hides the messy complexities of infrastructure from the development team. 

This ensures that an integrated software suite behaves identically whether it is running on a developer's local machine, inside a user acceptance testing (UAT) pilot environment, or at scale in production.

---

## Types of platforms

Modern enterprise integration relies primarily on three distinct categories of platforms. 

*First is Platform as a Service (PaaS)* 
- AWS Elastic Beanstalk or Heroku, where developers simply upload code and leave scaling, load balancing, and OS maintenance to the cloud provider. 

*Second is Integration Platform as a Service (iPaaS)* 
- such as MuleSoft or Dell Boomi, which are cloud environments purpose-built to connect disparate enterprise software applications via pre-built connectors, drastically reducing custom integration work. 

*Finally, Container and Orchestration Platforms*, 
- heavily dominated by Kubernetes and Red Hat OpenShift, manage the automated deployment, scaling, and networking of microservices across clusters of machines, serving as the standard blueprint for modern cloud-native architectures.

---

## platform vs infrastrcuuture vs middleware

To firmly grasp how these layers interact, it is helpful to look at them through an architectural analogy. 

**Infrastructure** represents the *raw land*, the concrete foundation, and the physical utility pipes buried under a building. 

The **Platform** is the pre-constructed apartment building framework erected on that land, complete with working elevators, shared electrical grids, and a standard floor plan that makes the space immediately usable. 

Finally, **Middleware** represents the building's internal systems, such as the shared intercom network, the security checkpoint at the front door, and smart-home hubs that allow distinct appliances to communicate. 

Together, they create an *ecosystem* where the top-floor apartment (your actual application) can function seamlessly.

---

## layout: center

# Integration Techniques

---

## Wrappers

The wrapper technique involves *enclosing* an existing piece of software, a legacy database, or a third-party component within a completely new interface. 

This is heavily utilized when an organization relies on a **mission-critical legacy system**

- such as a decades-old php university management system 

Or an on-premises mainframe that works perfectly but lacks the ability to communicate via modern web protocols like REST, GraphQL, or JSON. 

By writing a modern API wrapper around this system, developers create an intermediary layer. 

This wrapper accepts modern JSON requests from the web, translates them into the binary or legacy format the old system expects, triggers the operation, and then translates the output back into a clean format for the client.

---

## Glue Code

As the name implies, glue code is software written with the sole, *hyper-specific* purpose of connecting two or more software components that were never originally designed to work together. 

Glue code is characterized by its *complete lack of internal business logic*; it does not calculate tax, process orders, or authenticate users.

Instead, it serves purely as an administrative bridge, taking the output of System A, converting the data types or formatting, and passing it immediately as the input to System B. 

While indispensable for rapid prototyping and quick system linkages, an over-reliance on glue code introduces severe *technical debt*, often creating a fragile "spaghetti integration" that is incredibly difficult to test, maintain, or benchmark.

---

## Facades

Derived from the classic structural design pattern, a facade provides a *simplified, unified, and clean interface* to a highly complex and chaotic subsystem behind it. 

In enterprise integration, a single business transaction (such as a customer placing an e-commerce order) frequently requires *coordinated interactions* with an inventory system, a payment gateway, a shipping provider, and a CRM tool simultaneously. 

Forcing a frontend application to manage all four of these distinct API connections creates a maintenance nightmare. 

By implementing an API Facade, such as an *OrderProcessingService*, the client application interacts with a single, elegant endpoint. 

The facade *handles the underlying complexity*, orchestrating the calls to the separate subsystems in the correct sequence and returning a clean, *consolidated* response to the user.
