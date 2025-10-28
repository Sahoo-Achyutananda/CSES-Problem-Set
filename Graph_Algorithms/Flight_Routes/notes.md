Visited will cause trouble here
### Correct Way (Why visited isn’t used)
- We never use visited[] here because:
- A node can appear in multiple different routes.
- We want to expand up to k times per node, each time possibly via a new shorter route.
- The PQ naturally ensures the order of discovery is from smallest to largest cost.

Instead, the control condition is:
```bash
if (dist[u].size() == k && d > dist[u].back()) continue;
```