# PART A – DESIGN (25 Marks)

## TASK A1 – Design the Polymorphic Bill Hierarchy

### A1.1 Common interface
Every bill provides `total()`, `type()` and `print()`. Common data includes patient details, bill number and billing date. `total()` returns the calculated amount; `type()` identifies the bill; `print()` displays its details.

### A1.2 Hierarchy
`Bill` is an abstract base class with pure virtual `double total() const = 0` and `string type() const = 0`, a concrete `print() const`, and a virtual destructor. Derived classes are `OutPatientBill`, `InPatientBill`, `DayCareBill` and `EmergencyBill`.

```text
                 <<abstract>> Bill
          total() = 0; type() = 0; print()
                    virtual destructor
        ______________|________________________
       |              |            |            |
 OutPatientBill InPatientBill DayCareBill EmergencyBill
   total()         total()      total()      total()
   type()          type()       type()       type()
```

### A1.3 Process bills

```text
ALGORITHM CalculateDailyTotal
    totalAmount <- 0
    FOR EACH bill IN arrayOfBillPointers
        totalAmount <- totalAmount + bill.total()
        bill.print()
    END FOR
    DISPLAY totalAmount
END ALGORITHM
```

**Alternative (one structure and switch):** Store a type tag and the fields needed for each bill in one structure. `total()` switches on the tag and evaluates the matching formula. Both approaches take O(n) time for n bills. Both use O(n) storage for n records. Adding a type to the polymorphic design means adding a derived class; the switch design requires editing the switch and central structure, increasing coupling.

## TASK A2 – Runtime Binding

### A2.1 Early and late binding
Early binding resolves a non-virtual call at compile time. Late binding resolves a virtual call at runtime using the dynamic type of the object. For `Bill* b = new OutPatientBill(...); b->total();`, the overridden `OutPatientBill::total()` is selected.

### A2.2 Conceptual vtables

```text
Bill vtable:             OutPatientBill vtable:
  total -> pure virtual     total -> OutPatientBill::total
  type  -> pure virtual     type  -> OutPatientBill::type
  destructor               destructor -> OutPatientBill::~OutPatientBill

InPatientBill vtable:
  total -> InPatientBill::total
  type  -> InPatientBill::type
  destructor -> InPatientBill::~InPatientBill
```

A base pointer points to an object whose runtime type determines the vtable used for the virtual call. A vtable is a common implementation technique, not a layout guaranteed by the C++ language standard.

### A2.3 Virtual destructor
A base class deleted through a base pointer needs a virtual destructor. Otherwise, deleting a derived object through that pointer has undefined behaviour. With a virtual destructor, the derived destructor runs before the base destructor.

**Predict-output program:** `500 ~OPBill ~Bill` followed by a newline. `show()` is non-virtual, but its call to virtual `total()` is dynamically dispatched. Removing `virtual` from `~Bill` makes `delete b` undefined behaviour; do not rely on a particular output or sanitizer diagnostic.

**Alternative using casts:** If `total()` is non-virtual, code can test the dynamic type with `dynamic_cast` and call type-specific functions. In the worst case it may perform up to k casts for k bill types per bill, versus one virtual dispatch. A polymorphic object commonly stores a hidden vptr, often one pointer in size, but the exact layout is implementation-dependent.

## TASK A3 – Abstract Payer Classes

`Payer` is abstract and declares `virtual double amountCovered(const Bill&) const = 0` and a virtual destructor. `SelfPay` covers the full bill. `Insurance` stores a cover limit and co-payment percentage and computes the covered amount according to the policy. `GovernmentScheme` stores fixed package rates and returns the applicable package coverage. A `CorporatePayer` can be added as another derived class without changing existing payer classes.

**Alternative using `std::function`:** Store a callable policy, such as `std::function<double(double)>`, and capture policy data (for example, a limit) in the callable. Both a virtual call and a function-object call are O(1) per invocation. The class design groups behaviour and state in named types; `std::function` offers flexible runtime policy composition but may have type-erasure/storage overhead.

## TASK A4 – Exception Strategy

Possible errors: negative charges, claims above cover, unknown package code, missing patient record, invalid numeric text (`std::invalid_argument`), out-of-range numeric input, and allocation failure (`std::bad_alloc`). A domain hierarchy can be `std::exception -> std::runtime_error -> BillingError -> ClaimError`, with further domain-specific subclasses where useful. `std::bad_alloc` and standard conversion exceptions remain standard-library exceptions.

Functions that validate input, calculate/approve claims, look up records or parse values may throw. Destructors and cleanup functions should not throw; destructors should be `noexcept` so an exception during stack unwinding does not cause termination. A virtual destructor is appropriate for polymorphic base classes.

**Alternative return codes:** Return an enum/status or an optional/result object with an error message. Normal-path work remains O(1) per validation and error-path work is also O(1), excluding message construction. Return-code callers must check and propagate status explicitly; this adds branching and result/message storage. Exceptions separate exceptional paths from ordinary flow but are expensive when thrown frequently.

## TASK A5 – Recovery and Rethrowing

Catch close to a layer that can add useful context or recover. A lower layer may log context and use `throw;` to preserve the original exception; the application boundary catches `std::exception` and reports a safe message to the user. Avoid logging the same error repeatedly at every layer.

Stack unwinding destroys automatic objects in reverse construction order as an exception leaves scopes. RAII types such as `std::string`, `std::vector`, `std::unique_ptr` and file streams release resources in their destructors.

**Predict-output program:** `~f ~main caught 42` followed by a newline. The local `Guard` in `f()` is destroyed first, then `Guard m` in `main()`. `not printed` is skipped because the throw transfers control to a matching handler.

**Alternative manual cleanup:** Explicit `delete` in each catch/error branch has similar resource-release time for a given object, but duplicates cleanup and creates leak/double-delete risks whenever a new exit path is added. RAII centralizes cleanup in destructors.
