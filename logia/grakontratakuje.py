
def main(balls):
    computed = dict()

    def score(balls, summed):
        if len(balls) == 1:
            return balls[0]
        elif str(balls) in computed:
            # print("Reused!")
            return computed[str(balls)]
        else:
            result = max(summed - score(balls[1:], summed - balls[0]),
                         summed - score(balls[:-1], summed - balls[-1]))
            computed[str(balls)] = result
            return result
    min_score_2 = None
    for i in range(len(balls)):
        balls_2 = balls.copy()
        balls_2.pop(i)
        if min_score_2:
            min_score_2 = min(min_score_2, score(balls_2, sum(balls_2)))
        else:
            min_score_2 = score(balls_2, sum(balls_2))
    return sum(balls) - min_score_2


if __name__ == "__main__":
    print(main([4, 5, 1, 2, 3]))
    # print(main([1,5,4,2]))
    # print(computed)
