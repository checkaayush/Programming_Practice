"""Write a python program to validate an email address without using regex."""


def is_email_valid(email):
    try:
        username, url = email.split("@")
        website, extension = url.split(".")
    except ValueError:
        return False

    if not username.replace("-", "").replace("_", "").isalnum():
        return False
    if not website.isalnum():
        return False
    if len(extension) > 3:
        return False
    return True


def main():
    email = input('Enter email: ').strip()
    if is_email_valid(email):
        print('{} is a valid email address.'.format(email))
    else:
        print('{} is an invalid email address.'.format(email))


if __name__ == '__main__':
    main()