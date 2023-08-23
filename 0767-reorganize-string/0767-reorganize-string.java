class Solution {
    public String reorganizeString(String S) {
        Map<Character, Integer> charCount = new HashMap<>();
        for (char c : S.toCharArray()) {
            charCount.put(c, charCount.getOrDefault(c, 0) + 1);
        }

        PriorityQueue<Character> maxHeap = new PriorityQueue<>((a, b) -> charCount.get(b) - charCount.get(a));
        maxHeap.addAll(charCount.keySet());

        StringBuilder result = new StringBuilder();
        char prevChar = '\0';

        while (!maxHeap.isEmpty()) {
            char currentChar = maxHeap.poll();
            result.append(currentChar);
            charCount.put(currentChar, charCount.get(currentChar) - 1);

            if (prevChar != '\0' && charCount.get(prevChar) > 0) {
                maxHeap.offer(prevChar);
            }

            prevChar = currentChar;
        }

        return result.length() == S.length() ? result.toString() : "";
    }
}