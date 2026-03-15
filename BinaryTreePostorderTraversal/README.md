# PostOrder traversal

## Algorithm

perform action when node is visited for last time.

## Mnemonics

- start with node status and not stack
- if node is not null add it to stack and add all left nodes - left hand to get lift and hop into car (left childrens will be added to stack in ONESHOT)
- if node is null and stack is not empty, get the element out from stack and process it as because it is already visited.
- Upto above all same as inroder traversal
- if the node has right childern then update the node as node's right ways BEFORE poping / processing
- else follow stack pop as in inorder traversal and update lastvisited node and process the node
- Very important to reset node to nullptr in else case where pop and operation is performed else there will be TLE.
