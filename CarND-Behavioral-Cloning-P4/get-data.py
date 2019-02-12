if True:
    from google_drive_downloader import GoogleDriveDownloader as gdd

    RUN = 2
    if RUN == 1:
        gdd.download_file_from_google_drive(file_id='1t-67sz6_ZutHjrEsvlBAFJoum1hhdMJk',
                                        dest_path='./data/run1/IMG.zip',
                                        unzip=True)
    if RUN == 2:
        gdd.download_file_from_google_drive(file_id='19-n8peD4u6sjg5jmMXXZB0AMnKV3cSEw',
                                        dest_path='./data/run2.zip',
                                        unzip=True)