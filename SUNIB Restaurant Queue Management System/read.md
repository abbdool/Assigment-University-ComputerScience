# SUNIB Restaurant Queue Management System

## Problem Description

SUNIB Restaurant requires a program to manage their priority-based queue reservation system. The system must handle customers according to their membership status while maintaining a fair first-come-first-served policy for customers with equal priority.

### Membership Hierarchy
1. **VVIP** (Highest priority)
2. **VIP**
3. **Member**
4. **Guest** (Lowest priority)

### Program Requirements

#### Core Features
- Manage customer queues based on membership status
- Implement First-In-First-Out (FIFO) for same-priority customers
- Provide five main menu options

#### Menu Operations

1. **Add Customer to Queue**
   - Input format: `[Membership Status] [Customer Name]`
   - Example: `VVIP John_Doe` or `Guest Jane_Smith`
   - Membership status must be one of: VVIP, VIP, Member, Guest
   - Names may contain underscores (will be displayed with spaces)

2. **Serve One Customer**
   - Serves the highest-priority customer first
   - Customized announcement messages:
     - VVIP: `"Attention! [name] is being served at VVIP table."`
     - VIP: `"Attention! [name] is being served at the VIP table."`
     - Member: `"Attention! Member [name] is being served at regular table."`
     - Guest: `"Attention! Guest [name] is being served at a regular table."`
   - Removes served customer from queue

3. **Serve All Customers**
   - Processes all queued customers in priority order
   - Uses same announcement format as "Serve One"
   - Clears the entire queue after serving

4. **Dismiss Queue**
   - Displays: `"End of the day."`
   - Clears all customers without serving

5. **Exit Program**
   - Terminates the application

#### Interface Requirements
- Persistent display of current waiting line status
- Menu navigation via numeric input (1-5)
- Clear visual separation between operations

### Technical Specifications
- Program must initialize with empty queue
- Input validation for membership status
- Proper queue management with efficient insertion/removal
- Case-sensitive membership status handling

### Example Scenarios

#### Adding Customers
