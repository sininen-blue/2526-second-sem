A hypervisor creates isolated VMs on one server. Later, networking and storage are provisioned through software APIs. This progression describes:
- Virtualization evolving into software-defined infrastructure
- Bare metal provisioning replaced by platform-as-a-service
- Hybrid cloud architecture
- Containerization replacing virtualization

---

A hospital keeps patient records on private servers for compliance and runs a patient portal on AWS. Which factor is the primary difficulty?
- Integration, moving data securely between on-premises and cloud environments
- Vendor lock-in, migrating workloads away from the provider becomes expensive
- Performance latency, portal requests must traverse the public internet
- Compliance drift, regulations change faster than audits can track

---

A team uses Express.js middleware for authentication on HTTP requests. Another uses Kafka to decouple services through message queues. A third uses Prisma to translate objects into SQL. Which statement is correct?
- All three are middleware, though the term's meaning varies by context
- Only Kafka is middleware, Express.js is application logic, Prisma is a database tool
- Express.js and Kafka are middleware, Prisma is a platform
- All three are platforms, not middleware

---

In the building analogy, infrastructure is the foundation, the platform is the building, and middleware is the intercoms. A team runs containers on Kubernetes across EC2 instances. Which mapping is correct?
- EC2 is infrastructure, Kubernetes is a platform, a service mesh is middleware
- EC2 is a platform, Kubernetes is infrastructure, containers are middleware
- Kubernetes is a platform, EC2 is middleware, the application is infrastructure
- EC2 and Kubernetes are both infrastructure, no middleware is involved

---

A mainframe only processes COBOL. A new service accepts REST/JSON, translates to COBOL, and converts responses back. Which integration technique is this?
- Wrapper, places a modern interface around a legacy system
- Glue code, software that connects systems never designed to work together
- Facade, a unified interface hiding complex subsystems
- Message broker, an intermediary for asynchronous communication

---

A team skips integration and system testing, deploying straight to staging to accelerate delivery. What is the primary risk of bypassing intermediate gates?
- A skipped gate lets failures reach later stages where they cost more to fix
- Skipping gates is fine if staging catches all issues before production
- The main concern is reduced familiarity with testing tools
- Integration tests are redundant because unit tests verify interactions

---

Staging uses MySQL while production uses PostgreSQL. A MySQL-specific query passes in staging but crashes in production. This violates:
- Environment parity, staging must mirror production to catch config issues
- Canary release discipline, the change should have reached fewer users first
- Gate-based progression, staging should block deployments with mismatches
- Automated rollback, monitoring should have reverted the deployment

---

A feature is deployed disabled, enabled for 2% of users, monitored, and gradually increased to 100%. Which classification best fits?
- Feature flags + canary
- Blue-green deployment
- Feature flags alone
- A/B testing

---

An auth library deprecates its old API. The app still works, but a future update will remove the old API entirely. The team updates to the new API. Which type of support is this?
- Adaptive support, keeping software compatible with an updated third-party API
- Corrective support, fixing deprecation warnings that indicate defects
- Perfective support, improving performance based on user feedback
- Preventive support, clearing technical debt before it causes incidents

---

An SLA guarantees 99.99% uptime. How much annual downtime does this allow, and what is noted about this target?
- ~52.6 min/yr, costly, impractical for small teams
- ~8.7 hours, achievable with standard cloud monitoring
- ~43.8 hours, requires manual failover procedures
- ~5.2 minutes, expected minimum for all production systems

---

Before virtualization, organizations relied on physical servers, Ethernet cables, and hardware firewalls in data centers. Which disadvantages are associated with this approach?
- Expensive, slow to scale, vulnerable to single points of failure
- Incompatible with modern languages, difficult to secure, prone to data loss
- Limited to one OS, cannot run multiple applications, costly to maintain
- Fast to deploy, but prohibitively expensive for small teams

---

A game team uses Unreal Engine, Havok for physics, and Wwise for audio. Which classification is correct?
- Havok and Wwise are middleware, Unreal Engine is an engine
- All three are middleware since they sit between game code and the OS
- Unreal Engine and Havok are middleware, Wwise is a platform
- None are middleware, game tools are classified only as platforms

---

A startup wants developers to deploy without managing servers, but needs on-premises container support later. Which approach fits both?
- Start with PaaS like Elastic Beanstalk, then Kubernetes for on-premises control
- Start with IaaS like raw EC2, manually configure scaling and balancing
- Use iPaaS like MuleSoft for deployment and integration
- Deploy to bare metal and use hypervisors without cloud involvement

---

Processing an order requires inventory, payment, shipping, and CRM updates. The client sends one request to an OrderProcessingService instead of managing each integration directly. Which technique is this?
- Facade, a unified interface that coordinates behind the scenes
- Wrapper, wrapping each backend system with a modern API
- Glue code, connecting several systems not designed to work together
- Message broker, decoupling the request from downstream services

---

A faulty CrowdStrike config crashed 8.5 million devices in 2024, grounding flights and canceling surgeries. This example illustrates:
- That release management prevents failures and makes changes safe to ship
- The importance of blue-green deployments for security software
- Why enterprises should avoid third-party security vendors
- That even configuration changes need dedicated staging environments

---

What distinguishes UAT from other testing phases?
- UAT focuses on business value, not technical correctness
- UAT is the only phase that uses real production data
- UAT is performed by developers to verify technical requirements
- UAT replaces system testing and validates the full application

---

Two identical production environments exist. V1 runs in A. V2 is deployed to B, validated, then traffic switches to B. A stays ready for rollback. This describes:
- Blue-green deployment
- Canary release
- Feature flags
- Rolling update

---

An operations team schedules monthly security patching, dependency updates, and backup verification to prevent outages. This is classified as:
- Preventive maintenance, proactive work that prevents incidents
- Corrective maintenance, fixing systems after failures
- Adaptive maintenance, ensuring compatibility with changing environments
- Perfective maintenance, improving performance and efficiency

---

A server crashes every three weeks from a memory leak. The team restarts it each time, but the same crash recurs. What is missing?
- Problem management, finding and fixing the root cause
- Incident management, documenting each occurrence separately
- A knowledge base entry documenting the restart procedure
- An SLA with response time commitments

---

A team tracks total operational time divided by number of failures, and percentage of tickets resolved without escalation. These are:
- MTBF and FCR
- MTTR and SLA Compliance Rate
- MTBF and User Satisfaction
- Uptime and Ticket Volume
