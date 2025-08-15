# Object-Oriented Programming in C++ 
A curated, code‑first walkthrough of core OOP concepts in modern C++. Each topic lives in its own folder with focused examples you can compile and run. Ideal for learners who want to *see* the idea, tweak it, and build an intuition through experiments.

> Quick start: clone → pick a concept folder → build the sample(s) with g++ → run and tweak.
> 

---

## Repository map

The repository is organized by concept. As of now you’ll find the following top‑level directories:

- `Encapsulation/` — Modeling data with clear interfaces; access modifiers; getters/setters vs. invariants; class boundaries in practice.
- `abstraction/` — Hiding complexity behind clean APIs; pure interfaces; separating *what* from *how*; when to prefer composition or templates for abstraction.
- `composition/` — “Has‑a” relationships; object lifetimes and ownership; delegating behavior to contained objects.
- `inheritance/` — “Is‑a” relationships; base/derived design; virtual destructors; when inheritance is appropriate (and when it isn’t).
- `polymorphism/` — Compile‑time and run‑time polymorphism; virtual dispatch; overriding; function/operator overloading; interface‑driven design.

> These folders typically contain: a short README describing the idea, one or more .cpp examples, and sometimes a small Makefile or build note. Names may vary slightly per folder as the repo evolves.
> 

---

## What you’ll learn here

- **Core OOP pillars, applied**: encapsulation, abstraction, composition, inheritance, and polymorphism—implemented in C++ with idiomatic patterns.
- **Design trade‑offs**: when to reach for a tool (e.g., inheritance) and when to avoid it in favor of composition or templates.
- **Mechanics under the hood**: virtual tables & dispatch, object layout implications of inheritance, access control at compile time, and how these choices affect safety and performance.
- **Modern C++ habits** (where relevant): RAII, rule of zero/five, smart pointers for ownership, `override`/`final`, and clean interfaces.

---

## Suggested learning path

1. **Encapsulation → Abstraction**: lock in the boundary between data and behavior, then generalize the interface.
2. **Composition**: prefer building complex behavior by combining simpler parts.
3. **Inheritance → Polymorphism**: learn when dynamic dispatch and base classes make sense, and their costs.
4. **Refactor**: revisit the earlier examples applying RAII, `override`, and cleaner interfaces.

---

## Explore like a pro

- Read each folder’s **README** first for intent, then dive into the code.
- Build, run, and **modify**: add a method, change visibility, introduce a bug—observe compiler feedback and runtime behavior.
- Sketch **UML‑lite**: boxes and arrows help reason about composition vs. inheritance.
- Compare **alternatives**: rewrite an inheritance example using composition or templates and note the differences.