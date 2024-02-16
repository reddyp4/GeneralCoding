

#Recursive Solution
'''
def levenshtein_distance(word1, word2):
    """
    Args:
     word1(str)
     word2(str)
    Returns:
     int32
    """
    # Write your code here.
    #According to Wiki, Leven=len(a) or len(b) is one string is empty
    #or if first charactses are same, take leven(tail(a),tail(b))
    #else: min of leven(tail(a),b) level(a,tail(b)), leven(tail(a),tail(b))
    len1,len2=len(word1),len(word2)
    print("word1:",word1,"word2:",word2)
    if(word1==word2):
        return 0
    if(len1==0 and len2==0):
        return 0
    if(len1==0):
        return len2
    if(len2==0):
        return len1
    count=0
    if(word1[0]==word2[0]):
        count=levenshtein_distance(word1[1:],word2[1:])
    elif(word1[1:]==word2[1:]):
        count=1
    else:
        val1=levenshtein_distance(word1[1:],word2)
        val2=levenshtein_distance(word1,word2[1:])
        val3=levenshtein_distance(word1[1:],word2[1:])
        count=1+min(val1,val2,val3)
    return count
'''

def printMatrix(DP):
    for i in range(len(DP)):
        print(DP[i])

#DP: Save the initial values, and store DP[i,j], Goal is to make an identity matrix

def levenshtein_distance(word1, word2):
    count=0
    len1,len2=len(word1),len(word2)
    DP=[[0]*len2 for i in range(len1)]
    for i in range(len1):
        for j in range(len2):
            if(word1[i]==word2[j]):
                DP[i][j]=1
    printMatrix(DP)
    return count

#word1,word2="bat","cat"
word1,word2="aakitten","sitting"

print("distance:",levenshtein_distance(word1,word2))

'''
{
"word1": "masilanidbny",
"word2": "zwujtimkexcgvxrgkp"
}
exp:17

{
"word1": "fifsmivvlq",
"word2": "fpypvzeidrssnwlxss"
}
exp:15

{
"word1": "wvksnuxaldljqcjqnazsfoxqbylzhtcbvtpqqvkjhoqyrmdpjpxmzxvaulvbkyeyewlhuuutcpugkmqfhwwxwcdjyavnszhwth",
"word2": "opszfjkvkzjbgltaqnzytzwhiupbrioyttquvttipgefsuawjwzmkmhomkjpnafyacssguytebhcltwmqivuekhzivcqxmqkgwrfihaviegiroozb"
}
exp:93

{
"word1": "teoiemydyvzbmasngaehjdqhuxukayjlmqneywiwlyaycgivgxrpwfsxmwqptpqejarflnxqomtglkppxprlosrgyaasahlttfskufxpkftghizvpjhovcnclxmvzhkkzlthfhvmjtxwqhgufgnxaeewikxgwxlmmcphttlkgjbkcuznfukqdlzgrkearwdepgsdhbvxoikrtzkgshpvqnbwstxupmcqmfzmworyksnbaaxnbwtjgajkrdubgzusgzhdxvfsfmigjtyqeacqauzlxpotvaopaxpzycgzrdezutcnmkrsyejfzibxxsgwvinpgbpjdzqjtlgnjwmqzndzjyxlbzgjsityhvcaucatejrbbimutzamlymcuxtsnzdltwhwvviwxebpajsffmhyehywmzpllfyxvtsxzplqdediouosnltesbhomzabhgajfazjjcftkpibsfwqysckakrlqxvkoyfmuvnzfzbooew",
"word2": "gamkwnrqmlbasuqmldgsphnskyxznvjjmtouzesjubzkgszhcoxceashyfebaljlxyeyzlxfyvyaivweoijiuhbagqmgkrkmrogwmqibbiapbrfotrmjbxnvypuxlfqrgglemhtennchovvbddvvxamghbhaqvcraqcipxwyrvthkcvzqqvuhuajnihourferdxusgnrcrkryldheythtjlnftwgexhdxsngiuubeuzsbvtdzspwpxslhtpwpnydowmoestiqgcdfcnxpkvpcsejplbzaqndqmqdkqljxsudnbiwydisbklxljfufwkfhmvpljkipruqranqssfongbxvqfqwnabbrlgdmebgvzoqbsnvteyzyqdbkpmxhbtaqkxjrqxwptpsprgzlvpostojviasidekwjpnwhyhncuggynxibxjdtvxxhqebdsnuhfyqlkudbngtmopslvoegkpdqpiworgmojdfygwnhmgnoiukoqgrgmfxeyjlmsnzodvqg"
}
exp:454
'''