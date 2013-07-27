import os


def main():
    try:
        while True:
            exit_code = os.system("python -m cuwo.server")
            print " cuwo exited, exit code: ", exit_code
            if exit_code == 0:
                break
    except KeyboardInterrupt:
        pass

if __name__ == '__main__':
    main()
