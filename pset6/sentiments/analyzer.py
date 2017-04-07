import nltk

class Analyzer():
    """Implements sentiment analysis."""

    #positives/negatives is a path to their respective words list
    def __init__(self, positives, negatives):
        self.positives = set()
        positives = open("positive-words.txt", "r")
        for line in positives:
            if not line.startswith((";", " ")):
                self.positives.add(line.strip("\n"))
        positives.close()
        

        self.negatives = set()
        negatives = open("negative-words.txt", "r")
        for line in negatives:
            if not line.startswith((";", " ")):
                self.negatives.add(line.strip("\n"))
        negatives.close()
        
        
        
        
    #takes in a string to be analyzed
    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        #Each individual token contains a single word
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)
    
        score = 0
    
        for token in tokens:
            if token.lower() in self.positives:
                score += 1
            elif token.lower() in self.negatives:
                score -= 1
            else:
                continue
            
            
        return score