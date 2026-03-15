# Inorder traversal

## Algorithm

perform action when node is visited for second time.

## Mnemonics

- start with node status and not stack
- if node is not null add it to stack and add all left nodes - left hand to get lift and hop into car (left childrens will be added to stack in ONESHOT)
- if node is null and stack is not empty, get the element out from stack and process it as because it is already visited.
- update node to node's right (if nothing to process then update node as stack top and new node to nodes right)
- remember whenever items are picked from stack we should alway process one at a time and not one shot loops.
