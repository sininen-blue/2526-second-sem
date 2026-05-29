---
title: 04 Testing
exportFilename: exports/sia/04_testing
lineNumbers: true
---

# Testing and validating requirements

---

Various techniques can help you to evaluate the correctness and quality of your requirements. 

One approach is to quantify each requirement so that you can think of a way to measure how well a proposed solution satisfies it. 

use the term fit criteria to describe such quantifications. 

---

Verifying requirements to ensure that they have all the desired properties of high-quality requirements is also an essential activity. 

Validating requirements allows teams to build a correct solution that meets the stated business objectives. Requirements validation activities attempt to ensure that: 

- The software requirements accurately describe the intended system capabilities and properties that will satisfy the various stakeholders’ needs.
- The software requirements are correctly derived from the business requirements, system requirements, business rules, and other sources.
- The requirements are complete, feasible, and verifiable.
- All requirements are necessary, and the entire set is sufficient to meet the business objectives.
- All requirements representations are consistent with each other.
- The requirements provide an adequate basis to proceed with design and construction.

---

## reviewing requirements

Anytime someone other than the author of a work product examines the product for problems, a peer review is taking place. 

Reviewing requirements is a powerful technique for identifying ambiguous or unverifiable requirements, requirements that aren’t defined clearly enough for design to begin, and other problems.

Informal reviews are good for catching glaring errors, inconsistencies, and gaps

But it’s hard for a reviewer to catch all of the ambiguous requirements on his own. He might read a requirement and think he understands it, moving on to the next without a second thought

Another reviewer might read the same requirement, arrive at a different interpretation, and also not think there is an issue. If these two reviewers never discuss the requirement, the ambiguity will go unnoticed until later in the project

---

Formal peer reviews follow a well-defined process. 

A formal requirements review produces a report that identifies the material examined, the reviewers, and the review team’s judgment as to whether the requirements are acceptable. 

The principal deliverable is a summary of the defects found and the issues raised during the review. 

The members of a formal review team share responsibility for the quality of the review, although authors ultimately are responsible for the quality of the deliverables they create.

---

The best-established type of formal peer review is called an inspection. 

Inspection of requirements documents is one of the highest-leverage software quality techniques available

Detailed inspection of large requirements sets is tedious and time consuming

If you don’t have time to inspect everything, use risk analysis to differentiate those requirements that demand inspection from less critical, less complex, or less novel material for which an informal review will suffice

Inspections are not cheap. They’re not even that much fun. But they are cheaper—and more fun—than the alternative of expending lots of effort and customer goodwill fixing problems found much later on

---

Inspection

partiscipants

- author and peers
- sources of information
- people who will work using srs

stages

planning - scheduleing
prep - context - possible
inspection - discuss possible
rework - -> prep
follow up
baesline

defect checklist

---

challegnegs

large requirements documents

large inspection teams

geography

---

prototyping 

All kinds of prototypes allow you to find missing requirements before more expensive activities like development and testing take place. Something as simple as a paper mock-up can be used to walk through use cases, processes, or functions to detect any omitted or erroneous requirements. Prototypes also help confirm that stakeholders have a shared understanding of the requirements. Someone might implement a prototype based on his understanding of the requirements, only to learn that a requirement wasn’t clear when prototype evaluators don’t agree with his interpretation.

Proof-of-concept prototypes can demonstrate that the requirements are feasible. Evolutionary prototypes allow the users to see how the requirements would work when they are implemented, to validate that the result is what they expect. Additional levels of sophistication in prototypes, such as simulations, allow more precise validation of the requirements; however, building more sophisticated prototypes will also take more time

---

testing

You can begin deriving conceptual tests from user requirements early in the development process. 

Use the tests to evaluate functional requirements, analysis models, and prototypes. 

The tests should cover the normal flow of each use case, alternative flows, and the exceptions you identified during elicitation and analysis. 

Similarly, if you identified business process flows, the tests should cover the business process steps and all possible decision paths.

These conceptual tests are independent of implementation. For example, consider a use case called “View a Stored Order” for the Chemical Tracking System. Some conceptual tests are:

- User enters order number to view, order exists, user had placed the order. Expected result: show order details.
- User enters order number to view, order doesn’t exist. Expected result: Display message “Sorry, I can’t find that order.”
- User enters order number to view, order exists, user hadn’t placed the order. Expected result: Display message “Sorry, that’s not your order.”

Ideally, a BA will write the functional requirements and a tester will write the tests from a common starting point: the user requirements 

Ambiguities in the user requirements and differences of interpretation will lead to inconsistencies between the views represented by the functional requirements, models, and tests. 

As developers translate requirements into user interface and technical designs, testers can elaborate the conceptual tests into detailed test procedures.

---

Let’s see how the Chemical Tracking System team tied together requirements and visual models with early test thinking. 

Following are several pieces of requirements-related information, all of which pertain to the task of requesting a chemical.

Business requirement As described in Chapter 5 one of the primary business objectives for the Chemical Tracking System was to:

> Reduce chemical purchasing expenses by 25% in the first year.

Use case A use case that aligns with this business requirement is “Request a Chemical.” 

This use case includes a path that permits the user to request a chemical container that’s already available in the chemical stockroom. Here’s the use case description from Figure 8-3 in Chapter 8:

> The Requester specifies the desired chemical to request by entering its name or chemical ID number or by importing its structure from a chemical drawing tool. The system either offers the Requester a container of the chemical from the chemical stockroom or lets the Requester order one from a vendor.

Here’s a bit of functionality derived from this use case:

> If the stockroom has containers of the chemical being requested, the system shall display a list of the available containers.

> The user shall either select one of the displayed containers or ask to place an order for a new container from a vendor.

Dialog map Figure 17-6 illustrates a portion of the dialog map for the “Request a Chemical” use case that pertains to this function. 

As was described in Chapter 12 the boxes in this dialog map represent user interface displays, and the arrows represent possible navigation paths from one display to another. 

This dialog map was created far enough along in requirements development that the project participants were beginning to identify specific screens, menus, dialog boxes, and other dialog elements so they could give them names and contemplate a possible user interface architecture.

---

## Test

Because this use case has several possible execution paths, you can envision multiple tests to address the normal flow, alternative flows, and exceptions. 

The following is just one test, based on the flow that shows the user the available containers in the chemical stockroom.

> At dialog box DB40, enter a valid chemical ID; the chemical stockroom has two containers of this chemical. Dialog box DB50 appears, showing the two containers. Select the second container. DB50 closes and container 2 is added to the bottom of the Current Chemical Request List in dialog box DB70.

Ramesh, the test lead for the Chemical Tracking System, wrote several tests like this one based on his understanding of the use case. 

Such abstract tests are independent of implementation details. 

They don’t discuss entering data into specific fields, clicking buttons, or other specific interaction techniques. 

As development progresses, the tester can refine such conceptual tests into specific test procedures.

Now comes the fun part—testing the requirements. 

Ramesh first mapped each test to the functional requirements. 

He checked to make certain that every test could be “executed” by going through a set of existing requirements. 

He also made sure that at least one test covered each functional requirement. 

Next, Ramesh traced the execution path for every test on the dialog map with a highlighter pen. 

The shaded line in Figure 17-7 shows how the preceding test traces onto the dialog map.

By tracing the execution path for each test, you can find incorrect or missing requirements, improve the user’s navigation options, and refine the tests. 

Suppose that after “executing” all the tests in this fashion, the dialog map navigation line labeled “order new container” that goes from DB50 to DB60 in Figure 17-6 hasn’t been highlighted. 

There are two possible interpretations:

- That navigation is not a permitted system behavior. The BA needs to remove that line from the dialog map. If the SRS contains a requirement that specifies the transition, that requirement must also be removed.
- The navigation is legitimate, but the test that demonstrates the behavior is missing.

In another scenario, suppose a tester wrote a test based on his interpretation of the use case that says the user can take some action to move directly from dialog box DB40 to DB70. 

However, the dialog map in Figure 17-6 doesn’t contain such a navigation line, so that test can’t be “executed” with the existing requirements set. 

Again, there are two possible interpretations. You’ll need to determine which of the following is correct:

- The navigation from DB40 to DB70 is not a permitted system behavior, so the test is wrong.
- The navigation from DB40 to DB70 is legitimate, but the dialog map and perhaps the SRS are missing the requirement that is exercised by the test.

In these examples, the BA and the tester combined requirements, analysis models, and tests to detect missing, erroneous, or unnecessary requirements long before any code was written. 

Conceptual testing of software requirements is a powerful technique for controlling a project’s cost and schedule by finding requirement ambiguities and errors early in the game. As [ref046] pointed out,

Use cases and tests work well together in two ways: 

> If the use cases for a system are complete, accurate, and clear, the process of deriving the tests is straightforward. And if the use cases are not in good shape, the attempt to derive tests will help to debug the use cases.
