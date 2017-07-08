# ChinesePoker
An C++ application that plays (and learns) two variants of Chinese Poker (13 cards). This is an old pet project that I rebuilt from
scratch on multiple occassions due to a lack of source control and failing hard disks. Not this time!
Unfortunately, this version isn't complete and I don't plan to revisit it any time soon.

The app uses a fairly simple learning method: It keeps track of how often each specific hand wins/loses (every single combination, which is perhaps overkill),
and uses this database of win rates to find the arrangement of 13 cards with the highest expected win rate across all 3 hands. It will make sure a given hand
never exceeds the win rate of a hand that is higher in rank (keeps things logical in case n isn't sufficiently large to learn this naturally).

The main drawback is that context is missed; e.g. a 3-card hand of KKQ becomes much stronger when you are also holding aces, and this algorithm will miss that.
Nevertheless, it will match the play of experienced Chinese Poker players the vast majority of the time.
