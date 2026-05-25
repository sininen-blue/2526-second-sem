---
title: 02 Documentation
exportFilename: exports/sia/02_documentation
lineNumbers: true
---

# Documentation

---

## Software requirement specification (SRS) format

The *software requirement specification* (SRS) document is a comprehensive description of the intended purpose and environment for software under development. 

It fully describes what the software *will do* and how it will be *expected to perform*. 

The SRS document is used as a *reference* for the development team, stakeholders, and testers throughout the software development lifecycle.

---

## Format

1. Introduction
2. General Description
3. Functional Requirements
4. Non-functional Requirements
5. Performance Requirements
6. Design Constraints
7. Non-functional Attributes
8. Preliminary Schedule and Budget
9. Appendices

Note that this is **not** a formal document template, but a *general* outline of the sections that should be included 

The specific content and structure may vary depending on the project and organization.

---

## Introduction

1. The purpose of the document - Why this SRS exists.
2. The scope of the software - What the system will and will *not* do.
3. Overview - A roadmap for the rest of the document.

i.e.
> This document specifies the requirements for the "Smart Pantry" mobile app. It is intended for household managers to track grocery inventory and reduce waste. The scope includes barcode scanning, manual entry, and expiry notifications, but excludes direct online grocery ordering.

---

## General Description

1. objective of a user - What the user wants to achieve.
2. a user characteristic - Expectations about user skills and background.
3. features, benefits, importance - High-level summary of capabilities.

i.e.
> A household manager wants to avoid buying duplicate items (Objective). 

> Users are expected to be familiar with smartphone apps but are often multi-tasking (Characteristic). 

> The app provides real-time inventory visibility, saving money and reducing food waste (Benefit).

---

## Functional Requirements

1. Operation of the program is *fully explained* - Detailed behavior for *every system feature*.

i.e.
> When a user scans a product barcode, the system shall fetch the product name and category from a global database and add it to the user's current inventory list with a default quantity of one.

---

## Non-functional Requirements

1. *Performance* - Speed, response time, and resource usage.
2. *Security* - Data protection, privacy, and authentication.
3. *Usability* - Ease of learning, efficiency, and accessibility.
4. *Reliability* - Availability and fault tolerance.

i.e.
> The application shall synchronize inventory changes with the cloud database within 2 seconds of a network connection being available. All user credentials must be stored using industry-standard salted hashing algorithms.

---

## Performance, Constraints, and Attributes

- **Performance**: Quantitative requirements (e.g., "Must handle 1000 users").
- **Design Constraints**: Limitations on tools, languages, or hardware (e.g., "Must run on iOS 15+").
- **Non-functional Attributes**: Portability, maintainability, and testability.

i.e.
> The system must be developed using React Native to ensure cross-platform compatibility for both iOS and Android from a single codebase.

---

## Schedule, Budget, and Appendices

- **Schedule**: Major milestones and delivery dates.
- **Budget**: Estimated costs for development, hosting, and maintenance.
- **Appendices**: Glossary of terms, diagrams, and reference documents.

i.e.
> **Milestone 1**: Initial Prototype (June 15). 

> **Glossary**: "Inventory Sync" refers to the reconciliation of local and remote database states.

---

## *Activity*: SRS Document Creation

With the same groups as before, create an SRS document for the software project you have been assigned to

- pdf format
- groupname_srs.pdf
- each member must submit on NEO

deadline is the end of this class


