---
title: 10 Contracts
exportFilename: exports/sia/10_contracts
lineNumbers: true
---

# Contracts
Contracts, RFPs, and SOWs

---

## Contracts

A formal, legally binding agreement between an organization and a third-party vendor or service provider. 

In the context of system integration, contracts govern the *acquisition* of hardware, software *licenses*, *cloud infrastructure*, or *outsourced* development teams.

---

## Contracts

Beyond simply stating what is being bought, a strong IT contract *manages project risk*. Key elements include:

- *Financial Terms:* Payment schedules and budget caps.
- *Intellectual Property (IP):* Who owns the final code or system integration.
- *Liability & Termination:* How disputes are resolved and the conditions under which either party can walk away.

---

## Requests for Proposals (RFP)

A formal document issued by an organization to *solicit bids* from potential vendors for a specific IT project.

- Outlines the *business problem*, technical requirements, and project scope.
- Provides a *standardized evaluation* criteria for all bidders.
- Allows the buyer to *compare different vendor* architectures, timelines, and pricing before committing to a contract.

This would usually look like:

> We are seeking a vendor to provide a cloud-based Student Information System for 15,000 active students. 
>
> The system must natively integrate with Oracle Financials. 
>
> Please submit your technical architecture proposals, security compliance certifications, and estimated costs by October 1st.

---
layout: center
---

# Example contract excerpt after RFP

> This legally binds the university to pay $500,000 over 3 years, and legally binds Workday to provide the software licenses. 
> 
> It states that any legal disputes will be handled in the university's local courts and confirms that the university owns all the student data, not the vendor.

---

## Statement of Work (SOW)

*(Often referred to as Scope of Work)*

A detailed operational document that defines exactly **what** work will be performed by the vendor.

- *Tasks:* The specific development or integration activities required.
- *Deliverables:* The tangible outputs (e.g., UI mockups, database schemas, compiled code).
- *Milestones and Timelines:* Strict deadlines for when each phase of the project must be completed and handed over.

> Phase 1: The vendor will migrate 10 years of legacy enrollment data to the new cloud database by January 15th. 
>
> Phase 2: The vendor will build a custom API endpoint linking the new SIS to the existing Oracle Financials server by February 28th. 
>
> Phase 3: The vendor will conduct a 2-day training seminar for 10 university IT admins.

---

## Service Level Agreement (SLA)

A commitment between a service provider and a client defining **how well** the service or integration will perform.

- Defines *measurable*, non-functional performance metrics (e.g., 99.9% server uptime, API response times < 500ms, or 24-hour bug fix turnaround).
- Establishes monitoring mechanisms.
- Outlines *specific penalties* (like financial credits or contract termination) if the vendor fails to meet the agreed-upon standards.

> The cloud server must maintain 99.9% uptime. 
> 
> API queries between the SIS and Oracle Financials must resolve in under 800 milliseconds. 
> 
> If the system experiences unplanned downtime exceeding 4 hours during the crucial enrollment month of August, the vendor will credit the university 10% of that month's licensing fee.

---
layout: center
---

# Other common contracts

---

## Non-Disclosure Agreement (NDA)

A contract that *protects* sensitive information, trade secrets, and intellectual property shared between parties.

- Prevents vendors from sharing your internal "build" plans or strategic roadmap with competitors.
- Usually the *first* document signed before any technical details of an **RFP** are released.
- Ensures that proprietary knowledge remains confidential during the bidding process.

> The Recipient agrees to keep all 'Confidential Information' strictly confidential and shall not disclose it to any third party without prior written consent. This includes, but is not limited to, software architecture diagrams, business strategies, and unreleased product roadmaps

---

## Data Processing Agreement (DPA)

A legally mandated contract that defines *how a vendor must protect* and handle sensitive or regulated user data (e.g., GDPR).

- Critical when "buying" cloud services (SaaS/PaaS) where the vendor stores your customers' personal information.
- Outlines specific security standards and the vendor's liability in the event of a data breach.
- Ensures compliance with national and international data privacy laws.

> The Vendor shall process Personal Data only on documented instructions from the Client. The Vendor shall implement appropriate technical and organizational measures to ensure a level of security appropriate to the risk, including encryption and regular security audits
