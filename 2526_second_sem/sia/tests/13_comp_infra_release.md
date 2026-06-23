Here's the 20-item quiz:

---

1. What is a component in a system?
- A distinct part of a system that performs a specific responsibility and interacts through defined interfaces
- A large block of code that handles all system functions in a centralized manner
- A hardware device that connects multiple software modules through a network
- A document that describes how different parts of a system are organized and maintained

2. Which of the following best describes an interface in a software system?
- A contract between components that specifies what requests can be made, what information must be provided, and what results will be returned
- A physical cable or wireless signal that transmits data between two hardware devices
- A programming language used to write instructions that two components can both understand
- A user-facing screen that allows people to interact with the underlying application

3. What is the primary purpose of separating a system into components?
- To allow each part to focus on a specific task, making the system easier to understand and maintain
- To increase the total number of files and services so developers have more to work with
- To ensure that all parts of the system are written in the same programming language
- To make it harder for unauthorized users to access the system by hiding functionality

4. In the context of third-party components, what does "vendor dependency" refer to?
- The risk that an organization becomes reliant on an external provider whose changes or failures can impact the system
- The legal obligation to purchase hardware directly from the manufacturer of a software tool
- The requirement that all third-party services must be tested internally before use in production
- The process of auditing external code libraries to ensure they meet internal security standards

5. Which integration type connects systems that belong to the same organization?
- Internal integration, which links components like enrollment, billing, and student records within one institution
- External integration, which links components like payment gateways and shipping providers across organizations
- Horizontal integration, which merges multiple databases into a single unified data warehouse
- Vertical integration, which combines frontend, backend, and data layers into one monolithic application

6. What role does a driver play in a computer system?
- It acts as a translator between hardware and the operating system, enabling proper communication with devices like printers and graphics cards
- It manages user authentication by verifying credentials before granting access to hardware peripherals
- It converts API responses from external servers into a format readable by the local application
- It stores configuration settings for software components so they load correctly on startup

7. A university's enrollment system sharing data with its billing system is an example of what?
- Internal integration, where systems within the same organization are connected to share information
- External integration, where a university connects with a third-party payment processor for tuition
- API communication, where a mobile app sends a request to retrieve a student's current class schedule
- Component reusability, where the same login module is used across the student and faculty portals

8. Which of the following is NOT listed as a benefit of using third-party components?
- Full ownership of the source code, allowing unrestricted modification without licensing concerns
- Reduced development time by leveraging pre-built specialized functionality
- Lower costs compared to building every feature from scratch internally
- Access to external services with potentially higher reliability than in-house solutions

9. What distinguishes a REST API from a SOAP API?
- REST uses HTTP and JSON and is the most common modern web API style, while SOAP is an older enterprise technology often found in legacy systems
- REST requires XML formatting for all requests, while SOAP uses lightweight JSON for faster data exchange
- REST is exclusively used for mobile applications, while SOAP is designed for web browser communication
- REST encrypts all data by default, while SOAP relies on external security layers for data protection

10. In a food delivery application, which sequence correctly describes component communication when a customer places an order?
- The mobile app contacts the restaurant API, which updates the order database, then payment and notification services are called in sequence
- The SMS service first alerts the restaurant, which then contacts the payment gateway before the mobile app is notified of confirmation
- The payment gateway initiates contact with the mobile app, which then requests inventory data from the restaurant system
- The order database directly sends a request to the email service before any other component is involved in the process

11. What makes GraphQL different from REST APIs?
- GraphQL allows clients to specify exactly which data fields they need, avoiding over-fetching or under-fetching of information
- GraphQL requires all communication to occur over a specialized protocol rather than standard HTTP connections
- GraphQL is only used for internal integrations, while REST is designed exclusively for external integrations
- GraphQL automatically encrypts all queries and mutations before transmitting them to the server

12. Which category of component would a cloud storage service like AWS S3 fall under?
- A third-party component, since it is an external service integrated into the system rather than built in-house
- A hardware component, since cloud services rely on physical servers and networking equipment to operate
- A data component, since its primary function is storing and retrieving information for the system
- A backend component, since it processes business logic related to file management and access control

13. Why can component-based systems recover more gracefully from failures?
- Because failures can often be isolated to one component, allowing others like browsing and purchasing to continue functioning
- Because all components share a single codebase, making it easier to roll back changes during an outage
- Because hardware components automatically switch to backup software when a service goes offline
- Because third-party components include built-in redundancy that prevents any single point of failure

14. What is an SDK, and how does it differ from an API?
- An SDK is a collection of tools, libraries, and documentation that makes building integrations easier, while an API is the interface that defines how two components communicate
- An SDK is a security framework that validates API requests, while an API is the layer that encrypts data between components
- An SDK is used exclusively for mobile development, while an API is used only for connecting web-based services
- An SDK is an older standard replaced by modern APIs, retained only for backward compatibility in legacy systems

15. Which of the following best illustrates the concept of component reusability?
- A login component developed once and then used across web applications, mobile apps, and internal company systems
- A payment component updated without affecting the rest of the application due to proper interface design
- A frontend team and backend team working on different components of the same system simultaneously
- A recommendation system that fails independently without disrupting the browsing or checkout experience

16. In the mobile banking API example, what happens after the client sends a "check account balance" request?
- The server validates the user and retrieves account data before returning the current balance as a response
- The client immediately displays a cached balance while the server processes the request in the background
- The payment gateway intercepts the request to verify sufficient funds before the balance is displayed
- The database sends the balance directly to the mobile interface, bypassing the API processing layer

17. A hospital connecting its patient management, laboratory, pharmacy, and billing systems is an example of which integration benefit?
- Centralized information and consistent data across departments, leading to faster workflows and better reporting
- Expanded capabilities through external service providers like third-party diagnostic labs and insurance networks
- Improved customer experience by reducing the time patients spend providing the same information repeatedly
- Access to specialized functionality that would be too expensive to build and maintain entirely in-house

18. What is a key challenge of external integration that internal integration typically does not face?
- Security risks and compatibility issues arising from connecting to systems controlled by different organizations
- Difficulty sharing a consistent database schema across teams working in the same organization
- The need to rewrite existing components whenever a new internal service is added to the system
- Increased vendor dependency caused by having too many departments relying on a single shared data source

19. Which of the following scenarios best demonstrates the "maintainability" advantage of component-based systems?
- A payment component is updated with new fraud detection logic without requiring changes to the product catalog or user authentication
- A frontend team rewrites the entire website interface while backend developers simultaneously rebuild all APIs
- A database administrator migrates data to a new server, which automatically triggers updates in all connected components
- A third-party SMS provider is replaced with an in-house solution, requiring only minor adjustments to the notification component

20. In the online shopping system example, which component interaction occurs when a customer completes a purchase?
- The Order Service checks the Inventory Service, then requests the Payment Gateway, after which the Email and SMS Services send notifications
- The Payment Gateway directly updates the Product Database before the Order Service records the transaction details
- The Mobile Application contacts the SMS Service first to notify the customer, then communicates with the Payment Gateway
- The Inventory Service sends a request to the Email Service to confirm stock availability before payment is processed
