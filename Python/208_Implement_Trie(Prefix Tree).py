class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = Node()

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        currentWord = word
        currentNode = self.root
        i = 0
        while i < len(currentWord):
            if currentWord[i] in currentNode.children:
                if i == len(currentWord) - 1 :
                    currentNode.children[currentWord[i]].val = True
                currentNode = currentNode.children[currentWord[i]]   
            else:
                new = Node()
                if i == len(currentWord) - 1:
                    new.val = True
                currentNode.children[currentWord[i]] = new
                currentNode = new
            i += 1
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        currentWord = word
        currentNode = self.root
        i = 0
        while i < len(currentWord):
            if currentWord[i] in currentNode.children:
                currentNode = currentNode.children[currentWord[i]]
                i += 1
            else:
                return False
        if not currentNode.val:
            return False
        return True
    

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        currentPrefix = prefix
        currentNode = self.root
        i = 0
        while i < len(currentPrefix):
            if currentPrefix[i] in currentNode.children:
                currentNode = currentNode.children[currentPrefix[i]]
                i += 1
            else:
                return False
        return True
    
class Node:
    def __init__(self):
        self.val = False   
        self.children = {}

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)