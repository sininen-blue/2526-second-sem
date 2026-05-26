---
title: 03 Use Case Models
exportFilename: exports/sia/03_use_case_models
lineNumbers: true
---

# Use Case Models

---

## Use Case Diagrams

A use case model is a visual representation of the interaction between users (actors) and the system to achieve specific goals (use cases).

It defines **what** the system should do from the user's perspective, not how the system will do it

---

## Example

<img class="mx-auto rounded h-full" src="./images/use_case_diagram.jpg" alt="Use Case Diagram Example">

---

## Terms

- **Actor**: 

An entity that *interacts* with the system (e.g., user, *external system*).

- **Use Case**: 

A *specific function* or *action* that the system performs in response to an actor's request.

- **System Boundary**: 

A box that defines the *scope* of the system and separates it from *external actors*.

---

## Actor

An actor represents a role that interacts with the system. It can be a *person*, another *system*, or an *organization*.

<img class="mx-auto rounded w-1/2" src="./images/use_case_diagram.jpg" alt="Use Case Diagram Example">

---

## Use Case

A use case represents a *specific function* or *action* that the system performs in response to an actor's request. 

It describes a *sequence of interactions* between the actor and the system to achieve a particular *goal*.

<img class="mx-auto rounded w-1/2" src="./images/use_case_diagram.jpg" alt="Use Case Diagram Example">

---

## System Boundary

The system boundary is a box that defines the scope of the system and **separates** it from external actors.

<img class="mx-auto rounded w-1/2" src="./images/use_case_diagram.jpg" alt="Use Case Diagram Example">

---

## Benefits

1. **Clarity**: Use case diagrams provide a clear and *visual* representation of the system's functionality and its interactions with users.

2. **Communication**: They facilitate communication between stakeholders, developers, and designers by providing a *common language* to discuss system requirements.

3. **Requirement Analysis**: Use case diagrams help in identifying and analyzing the functional requirements of the system, ensuring that all necessary features are captured and understood.

> Note that any form of documentation, as long as it's thorough enough will help in indentifying requirements

---

## A note on UML

Use case diagrams are part of the *Unified Modeling Language* (UML), a standardized modeling language used in software engineering to visualize the design of a system.

One of the primary benefits of UML is that it provides a *common language for developers*, *designers*, and *stakeholders* to communicate and understand the structure and behavior of a system.

It was made in the 1990s by Grady Booch, Ivar Jacobson, and James Rumbaugh, who were working at Rational Software Corporation. 

They created UML to *unify the various modeling languages* that were being used at the time and to provide a standard way to visualize software design.

---

## Relationships

1. **Association**: A relationship between an actor and a use case, indicating that the actor participates in the use case.
2. **Include**: A relationship where one use case includes the behavior of another use case
3. **Extend**: A relationship where one use case extends the behavior of another use case under certain conditions.
4. **Generalization**: A relationship where one actor or use case is a specialized version

---

## Association

<img class="mx-auto rounded w-1/2" src="./images/use_case_association.webp">

Represents an *interaction* between an actor and a use case.

It's depicted by a line, and is used to show a **relationship**

Does not necessarily indicate a *direct* interaction, but rather that the actor is involved in the use case in some way.

---

## Include

<img class="mx-auto rounded w-1/2" src="./images/use_case_include.webp">

Represents a use case that *includes* the behavior of *another use case*.

It's depicted by a dashed arrow with the label "include", and is used to show that one use case is a *subroutine* of another use case.

It's primarly used for *modularity*

---

## Extend

<img class="mx-auto rounded w-1/2" src="./images/use_case_extend.webp">

Represents that a use case can be *extended* by another use case under certain conditions.

It's depicted by a dashed arrow with the label "extend", and is used to show that one use case can *add* behavior to another use case.

Mostly used for optional behavior that is not always executed, but can be executed under certain conditions.

---

## Generalization

An "**is-a**" relationship between actors or use cases, where one actor or use case is a *specialized version* of another.

Depicted by a *solid line with a hollow arrowhead* pointing from the specialized actor or use case to the more general actor or use case.

Fox example, a *vehicle renting system* having a "rent car" and "rent bike" which is a specialized version of "rent vehicle"

---

## Activity: Use case diagram

Choose one business scenario to create a Use Case Diagram for on the next slide

it must
- have at least *two actors*
- define at least *3-5 core* functionalities as use cases
- include a clear *system boundary*
- use  *association* relationships
- must include at least one "*include*" or "*extend*" relationship

use [draw.io](https://draw.io)

title it `lastname_firstname_usecase.png` and submit it to neo

---

## Activity: Use case diagram

1. **Local Bakery**: Automate customer order management and track real-time ingredient inventory.
2. **Pet Grooming Salon**: Manage appointment scheduling and maintain detailed customer pet profiles.
3. **Small Gym/Fitness Studio**: Track member monthly subscriptions and handle class bookings.
4. **Independent Bookstore**: Manage a digital book catalog and track sales/stock levels.
5. **Coffee Shop**: Streamline point-of-sale (POS) transactions and track customer loyalty rewards.
6. **Pharmacy**: Manage patient prescription records and automate medication refill alerts.
7. **Dry Cleaning Service**: Track garment processing status and notify customers when items are ready.
8. **Car Wash/Detailing**: Manage tiered service packages and schedule vehicle appointments.

