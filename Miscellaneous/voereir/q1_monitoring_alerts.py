"""You are building a monitoring and alerting system to detect API failures (5xx errors). If the
failure count in APIs are more than 10 in the last 5 mins you should alert the user. Monitoring
system is getting data in the form of stream containing two space separated integers,
timestamp and api status; like 1527271040 200.

The timestamp is in epoch format. Implement the identification mechanism for triggering alert to
user.

Sample data:

TimeStamp HTTP Status
1527270740 502
1527270800 500
...

Note - It is a continuous stream of data source. You can assume data source to be a file being
written with these two details per line by some other component. The alert should be sent in
realtime.
"""

import time


SLEEP_INTERVAL = 1.0
LAST_TIMESTAMP = 0
ERROR_COUNT = 0


def readlines_then_tail(fin):
    """Iterate through lines and then tail for further lines."""
    while True:
        line = fin.readline()
        if line:
            yield line
        else:
            tail(fin)


def tail(fin):
    """Listen for new lines added to file."""
    while True:
        where = fin.tell()
        line = fin.readline()
        print("LINE: {}".format(line))
        if not line:
            time.sleep(SLEEP_INTERVAL)
            fin.seek(where)
        else:
            yield line


def alert():
    print('Error code 5xx occured more than 10 times in last 5 minutes')


def should_alert(timestamp, code):
    global ERROR_COUNT
    global LAST_TIMESTAMP

    if code > 499:
        ERROR_COUNT += 1

    diff_secs = timestamp - LAST_TIMESTAMP
    if diff_secs >= 300: # 5 minutes in seconds
        LAST_TIMESTAMP = timestamp

    return ERROR_COUNT > 10


def process_line(line):
    try:
        parts = [int(p) for p in line.strip().split(' ') if p]
    except ValueError:
        print('Invalid log line: {}'.format(line))

    if len(parts) > 2 or len(parts) == 0:
        raise ValueError('Invalid log line: {}'.format(line))

    timestamp, code = parts[0], parts[1]
    if should_alert(timestamp, code):
        alert()
        global ERROR_COUNT
        ERROR_COUNT = 0


def main():
    filename = 'q1_monitoring.txt'
    with open(filename, 'r') as fin:
        for line in readlines_then_tail(fin):
            if not line.strip():
                continue
            print(line.strip())
            process_line(line)


if __name__ == '__main__':
    main()